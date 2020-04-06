#!/bin/bash

LIB_DIR="helper_files"

. "$LIB_DIR"/library.sh
. "$LIB_DIR"/gtest_running_utilities.sh
. "$LIB_DIR"/add_valgrind_to_gtest.sh

CPP_FILE_NAME="Project5.cpp"
test_timeout_seconds=1000

main "$@"
