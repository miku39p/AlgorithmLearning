#!/bin/bash

# Usage: ./scripts/run.sh <file.cpp>
# Compiles and runs tests automatically

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SRC_DIR="${SCRIPT_DIR}/../src"
TEST_FRAME="${SCRIPT_DIR}/../test_frame"

if [ $# -eq 0 ]; then
    echo "Usage: ./scripts/run.sh <file.cpp>"
    exit 1
fi

FILE="$1"
BASENAME=$(basename "$FILE" .cpp)

# Handle relative paths from src/
if [ -f "${SRC_DIR}/${FILE}" ]; then
    FILE="${SRC_DIR}/${FILE}"
elif [ ! -f "$FILE" ]; then
    echo "Error: $FILE not found"
    exit 1
fi

echo "Building and testing $FILE..."

# Check if test.h is included
if ! grep -q '#include "test.h"' "$FILE"; then
    echo "Warning: test.h not included. Add '#include \"test.h\"' to use TEST macros."
fi

# Compile with test framework
g++ -std=c++17 -I"${SRC_DIR}" -I"${TEST_FRAME}" "$FILE" "${TEST_FRAME}/test_runner.cpp" -o build/main 2>&1

if [ $? -ne 0 ]; then
    echo "Compilation failed!"
    exit 1
fi

# Run tests
./build/main
