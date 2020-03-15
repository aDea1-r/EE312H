#!/bin/bash

LIB_DIR="helper_files"
. "$LIB_DIR"/library.sh

declare -a SAMPLE_TEST_CASES=('Test_Provided_1' 'Test_Provided_2' 'Test_Provided_3');
CPP_FILE_NAME="Project4.cpp"
test_timeout_seconds=3

save_function brief_result_header_row previous_brief_result_header_row
save_function brief_result_error_row previous_brief_result_error_row

brief_result_header_row() {
    echo '"submission_name", "passed_tests", "total_tests", "uninitialized_count", "invalid_read_count", "invalid_write_count", "invalid_free_count", "bytes_leaked"'
}

brief_result_error_row() {
    echo "$1, \"0\", \"0\", \"N/A\", \"N/A\", \"N/A\", \"N/A\", \"N/A\""
}

perform_test_on_this_submission()
{
    enable_throwing_errors

	this_dir=$(pwd)
    total_num=0
    correct_num=0
    submission_name="${PWD##*/}"

    cp "$main_dir/helper_files/"*.h "$main_dir/helper_files/"*.cpp "$main_dir/helper_files/Makefile" .
    disable_throwing_errors

    if [[ $TA_MODE == true ]]; then
        make tests > /dev/null 2>&1
    else
        make tests
    fi

    enable_throwing_errors
    if [[ ! -f ./a.out ]]; then
        rm -f *.h *.cpp Makefile
        false
    fi

    for t_dir in "$tests_dir"/*/
    do
        cp "$t_dir/input.txt" "$t_dir/out.txt" .

        total_num=$(($total_num+1))
        printf "\n\n\n$t_dir\n" >> output_diff.txt

        if [[ $TA_MODE == true ]]; then
            timeout $test_timeout_seconds ./a.out input.txt \
                > actual_output.txt 2> /dev/null || true
            python2 "$main_dir/helper_files/rdiff.py" out.txt actual_output.txt >> output_diff.txt &&
                correct_num=$(($correct_num+1)) || true
        else
            timeout $test_timeout_seconds ./a.out input.txt \
                > actual_output.txt || true
            python2 "$main_dir/helper_files/rdiff.py" out.txt actual_output.txt >> output_diff.txt &&
                correct_num=$(($correct_num+1)) || echo "error on $t_dir"
        fi

    done
    rm -rf a.out* input.txt actual_output.txt out.txt

    disable_throwing_errors
    if [[ $TA_MODE == true ]]; then
        make valgrind > /dev/null 2>&1
    else
        make valgrind
    fi
    enable_throwing_errors
    rm -f *.h *.cpp Makefile
    if [[ ! -f ./a.out ]]; then
        false
    fi

    echo "timeout $test_timeout_seconds valgrind ./a.out" | bash &> valgrind_result.txt || true
    rm -rf a.out*
    read -r uni i_r i_w i_f b_l <<<$(python2 "$main_dir/helper_files"/valgrind_processor.py ./valgrind_result.txt)

    echo "\"$submission_name\", \"$correct_num\", \"$total_num\", \"$uni\", \"$i_r\", \"$i_w\", \"$i_f\", \"$b_l\"" \
        >> "$brief_feedback_file"
}

save_function prepare previous_prepare
prepare() {
    cp "$LIB_DIR/valgrind_processor.py" "$LIB_DIR/rdiff.py" "$main_dir/helper_files" > /dev/null 2>&1 || true
    previous_prepare
}

save_function clean before_previous_clean
clean()
{
    before_previous_clean
    rm -rf "$main_dir/helper_files/valgrind_processor.py" "$main_dir/helper_files/rdiff.py"
}

main "$@"
