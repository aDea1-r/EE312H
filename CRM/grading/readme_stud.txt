HOW TO RUN THE GRADING SCRIPT

These are instructions for running the grading script that we will use for grading your assignment. You must run this script on kamek.ece successfully, getting a perfect score for the 3 tests given to you.

As described in the project description, make your Project4.cpp.
Make a directory in kamek to run this script.  You may call it ~/EE312/Project2/GradingScript, for example.  Copy the sample_grading_script.zip to this folder, and unzip it using the unzip command.
Place Project4.cpp into the 'submissions' directory.
Then run ./grade.sh .
CAUTION: your submission file Project4.cpp will be deleted after grading, so keep a copy!
There are 3 tests in the testcases directory.
There are 6 sample fake submissions, so that you can see behavior of the script in case of compile/runtime errors as well. After running the script, the brief_results.csv file should be like this (line ordering may change):

"submission_name", "passed_tests", "total_tests", "uninitialized_count", "invalid_read_count", "invalid_write_count", "invalid_free_count", "bytes_leaked"
"compile_error", "0", "0", "N/A", "N/A", "N/A", "N/A", "N/A"
"infinite_loop", "0", "3", "0", "0", "0", "0", "0"
"link_error", "0", "0", "N/A", "N/A", "N/A", "N/A", "N/A"
"memory_leak", "1", "3", "0", "0", "0", "0", "1024"
"runtime_error", "0", "3", "0", "0", "1", "0", "0"
"some_credit", "1", "3", "0", "0", "0", "0", "0"

You may see brief_result.csv to see the abbreviated results and you may see detailed_feedback to see the detailed description about each test failure.
