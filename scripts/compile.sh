#!/bin/bash

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SRC_DIR="${SCRIPT_DIR}/../src"
TEST_FRAME="${SCRIPT_DIR}/../test_frame"

g++ -std=c++17 -I"${SRC_DIR}" -I"${TEST_FRAME}" "${1}" "${TEST_FRAME}/gdb_main.cpp" -g -o build/main
