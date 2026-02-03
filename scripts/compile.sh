#!/bin/bash

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SRC_DIR="${SCRIPT_DIR}/../src"
TEST_FRAME="${SCRIPT_DIR}/../test_frame"

# Compile with gdb_main.cpp as entry point, link test_runner.cpp for definitions
g++ -std=c++17 -DTEST_RUNNER_NO_MAIN -I"${SRC_DIR}" -I"${TEST_FRAME}" "${1}" "${TEST_FRAME}/gdb_main.cpp" "${TEST_FRAME}/test_runner.cpp" -g -o build/main
