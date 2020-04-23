HOW TO RUN THE GRADING SCRIPT

These are instructions for running the grading script that we will use for grading your assignment. You must run this script on kamek.ece successfully, getting a perfect score for the 3 tests given to you.

As described in the project description, make your submission zip file (at least containing Project7.cpp and CustomerDB.cpp; feel free to add more .cpp and .h files if you want). BE CAREFULL, WE WILL REPLACE YOUR MAIN FILE AND YOUR MAKEFILE. DO NOT RELY ON THE CHANGES YOU MAKE ON THOSE FILES.
Make a directory in kamek to run this script.  You may call it ~/EE312/Project7/GradingScript, for example.  Copy the sample_grading_script.zip to this folder, and unzip it using the unzip command.
Place zip file into the 'submissions' directory.
Then run ./grade.sh .
CAUTION: your submission zip file will be deleted after grading, so keep a copy!
There are 3 tests in the testcases directory.
There are 6 sample fake submissions, so that you can see behavior of the script in case of compile/runtime errors as well. After running the script, the brief_results.csv file should be like this (line ordering may change):

"submission_name", "passed_tests", "total_tests"
"compile_error", "0", "0"
"infinite_loop", "0", "3"
"link_error", "0", "0"
"runtime_error", "0", "3"
"some_credit", "1", "3"
"wrong_structure", "0", "0"

You may see brief_result.csv to see the abbreviated results and you may see detailed_feedback to see the detailed description about each test failure.
