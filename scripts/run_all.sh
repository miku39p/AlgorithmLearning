#!/bin/bash

# Run tests for all .cpp files in src/

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SRC_DIR="${SCRIPT_DIR}/../src"

echo "Running tests for all .cpp files in src/"
echo "============================================"
echo ""

total_passed=0
total_failed=0

for file in "${SRC_DIR}"/*.cpp; do
    if [ -f "$file" ]; then
        filename=$(basename "$file")
        echo ""
        echo ">>> Testing: $filename"
        echo "--------------------------------------------"

        "${SCRIPT_DIR}/run.sh" "$filename"
        result=$?

        if [ $result -eq 0 ]; then
            ((total_passed++))
        else
            ((total_failed++))
        fi

        echo ""
    fi
done

echo "============================================"
echo "Summary: ${total_passed} passed, ${total_failed} failed"
