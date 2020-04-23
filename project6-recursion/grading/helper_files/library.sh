#!/bin/bash

TA_MODE=false
PREPARING=false
CLEANING=false

function try() { [[ $- = *e* ]]; SAVED_OPT_E=$?;set +e;}
function throw() { exit $1;}
function catch() { export ex_code=$?;(( $SAVED_OPT_E )) && set +e;return $ex_code;}
function enable_throwing_errors() { set -e;}
function disable_throwing_errors() { set +e;}

main_dir=$(pwd)
submissions_dir="$main_dir/submissions"
tests_dir="$main_dir/test_cases"
brief_feedback_file="$main_dir/brief_results.csv"
detailed_feedback_dir="$main_dir/detailed_feedback"

brief_result_header_row() {
    echo '"submission_name", "passed_tests", "total_tests"'
}
brief_result_error_row() {
    echo "$1, \"0\", \"0\""
}

run_test_on_submissions()
{
    enable_throwing_errors

	cd "$submissions_dir"

    if ( ls *.cpp 1> /dev/null 2>&1 )
    then
	    for submission_raw_name in *.cpp
	    do
	    	submission_name="${submission_raw_name%%.*}"
            try
            (
	    	    submission_name="${submission_raw_name%%.*}"
                echo ""
	    	    echo "### going on: " "$submission_name"

	    	    mkdir "$submission_name"
                mv "$submission_raw_name" "$submission_name/$CPP_FILE_NAME"
	    	    cd "$submission_name"

	    	    perform_test_on_this_submission

	    	    cd "$submissions_dir"
            )
            catch ||
            {
                echo "###### submission format / compilation error on $submission_name"
                echo "$(brief_result_error_row \"$submission_name\")" >> "$brief_feedback_file"
                cd "$submissions_dir"
            }
	    done
    fi

	cd "$main_dir"
}

collect_results()
{
	mkdir -p "$detailed_feedback_dir"
	cd "$submissions_dir"
	for tested_submission in */
	do
		tested_submission=${tested_submission:0:${#tested_submission}-1}
		zip -ry9Tm "$tested_submission" "$tested_submission" > /dev/null
		mv "$tested_submission".zip "$detailed_feedback_dir"

	done
	cd "$main_dir"
}

grade()
{
    if [ -f ~/.profile ]
    then
        . ~/.profile
        module load gcc &> /dev/null || true
    fi

    enable_throwing_errors

    if [[ ! -f "$brief_feedback_file" ]]
    then
	    rm -rf  "$detailed_feedback_dir"
        echo "$(brief_result_header_row)" > "$brief_feedback_file"
    fi

	run_test_on_submissions
	echo "collecting results ..."
	collect_results
	echo "finished"

    disable_throwing_errors
}

main()
{
    while [[ $# > 0 ]]
    do
        arg="$1"
        case $arg in
            --ta)       TA_MODE=true;;
            --clean)    CLEANING=true;;
            --prepare)  PREPARING=true;;
        esac

        shift
    done

    if [[ $CLEANING == true ]]; then
        clean
    elif [[ $PREPARING == true ]]; then
        prepare
    else
        grade
    fi
}

prepare()
{
    if [[ $TA_MODE == true ]]; then
        rm -rf test_cases
        rm -rf submissions/*.cpp
        git checkout test_cases
    else
        mkdir "sample_tests"
        for tname in "${SAMPLE_TEST_CASES[@]}"; do
            mv "test_cases/$tname" "sample_tests"
        done
        rm -rf "test_cases"
        mv "sample_tests" "test_cases"
    fi
}

clean()
{
    rm -rf detailed_feedback brief_results.csv
    rm -rf submissions test_cases
    git checkout -- submissions test_cases
}

replace_library_inclusion()
{
    file_address="$1"
    library_address="$2"
    library_inclusion="LIB_DIR=\"$library_address\""

    cp "$file_address" temp.txt
    head -2 "$file_address" > temp.txt
    echo "$library_inclusion" >> temp.txt
    tail -n +4 "$file_address" >> temp.txt
    mv temp.txt "$file_address"
}

save_function()
{
    local ORIG_FUNC=$(declare -f $1)
    local NEWNAME_FUNC="$2${ORIG_FUNC#$1}"
    eval "$NEWNAME_FUNC"
}

prepare_student_version_of_grading_script()
{
    enable_throwing_errors

    here_dir=$(pwd)

    cd ../grading_and_solutions/grading
    ./grade.sh --clean
    cp ../../../../ta_codes_library/*.sh helper_files
    cp ../../../../ta_codes_library/*.py helper_files

    replace_library_inclusion grade.sh helper_files
        ./grade.sh --prepare &&
        rm -f readme_ta.txt &&

        cd ..

    zip -r9T grading grading > /dev/null &&
        cd grading

    rm -f helper_files/*.sh helper_files/*.py
    git checkout -- ./grade.sh

    ./grade.sh --clean
    git checkout -- readme_ta.txt
    cd "$here_dir"

    mv ../grading_and_solutions/grading.zip ./sample_grading_script/sample_grading_script.zip
    echo "done!"

    disable_throwing_errors
}

unzip_student_file() {
    path=$1
    unzip "$path" > /dev/null
    find . -name __MACOSX -exec rm -rfv {} \; > /dev/null 2>&1 || echo ""
}

flatten_all_file_types() {
    declare -a types_array=("${!1}")
    local temp_dir_name="very_temporary_directory_for_file_flatenning"

    rm -rf $temp_dir_name
    mkdir $temp_dir_name

    for t in "${types_array[@]}"; do
        find . -name "$t" | while read -r file_name; do
            mv "$file_name" "$temp_dir_name"
        done
    done
    mv "$temp_dir_name" ..
    rm -rf *
    mv "../$temp_dir_name" .
    mv "$temp_dir_name/"* .
    rm -rf "$temp_dir_name"
}
