#!/bin/bash

# Usage: ./run <file.cpp>
# Compiles and runs tests automatically

if [ $# -eq 0 ]; then
  echo "Usage: ./run.sh <file.cpp>"
  exit 1
fi

FILE="$1"
BASENAME=$(basename "$FILE" .cpp)

if [ ! -f "$FILE" ]; then
  echo "Error: $FILE not found"
  exit 1
fi

echo "Building and testing $FILE..."

# Check if test.h is included
if ! grep -q '#include "test.h"' "$FILE"; then
  echo "Warning: test.h not included. Add '#include \"test.h\"' to use TEST macros."
fi

# Compile with test framework
g++ -std=c++17 -I. "$FILE" test_runner.cpp -o build/main 2>&1

if [ $? -ne 0 ]; then
  echo "Compilation failed!"
  exit 1
fi

# Run tests
./build/main
