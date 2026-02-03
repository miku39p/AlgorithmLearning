# AGENTS.md - LeetCode C++ Repository Guidelines

This is a C++ LeetCode solution repository. All agents must follow these guidelines.

## Build, Test, and Run Commands

### Quick Test (Recommended)
```bash
./scripts/run.sh <file.cpp>
# Examples: ./scripts/run.sh LC154.cpp or ./scripts/run.sh src/LC406.cpp
```

### Manual Compilation
```bash
./scripts/compile.sh <file.cpp>

# Or manually compile
g++ -std=c++17 -Isrc -Itest_frame <file.cpp> test_frame/test_runner.cpp -o build/main
./build/main
```

### Debugging (GDB)
- VSCode configured with C++ debugger in `.vscode/launch.json`
- Launch debugger: `F5` in VSCode or run:
```bash
gdb ./build/main
```

### No Linting/Formatting Tools
- No ESLint, Prettier, or clang-format configured
- Use the test framework for automated testing

## Automated Testing System

### Overview
The repository uses a simple test framework (`test.h`) with a runner script (`./scripts/run.sh`).

### File Structure for Tests
Each `.cpp` file can optionally include test code:

```cpp
#include "basic.h"
#include "test.h"

int calc(int x, int y) { return x + y; }

void registerTests() {
    test_runner.addTest("description", []() {
        EXPECT_EQ(calc(3, 5), 8);
    });
}
```

### Test Framework API
```cpp
// Register tests
test_runner.addTest("test name", []() {
    // test code
});

// Assertions
EXPECT_EQ(actual, expected);
EXPECT_TRUE(condition);
```

### How `./scripts/run.sh` Works
1. Takes a `.cpp` file as argument
2. Checks for `#include "test.h"`
3. Compiles `file.cpp` + `test_runner.cpp` together
4. Runs the compiled binary
5. Executes all tests registered via `registerTests()`

## Code Style Guidelines

### File Organization
- Each LeetCode problem in a separate file: `LC<number>.cpp` (e.g., `LC154.cpp`)
- All source files in `src/` directory
- Use `basic.h` for common includes (`#include "basic.h"`)

### Includes and Headers
```cpp
#include "basic.h"  // Required in every file
```
`basic.h` includes: `<math.h>`, `<algorithm>`, `<map>`, `<string>`, `<vector>`, `<iostream>`, `<set>`, `<unordered_map>`, `<queue>`, `<stack>`, `<climits>`

### Naming Conventions
- **Functions**: camelCase (e.g., `findMin`, `reconstructQueue`)
- **Variables**: camelCase (e.g., `nums`, `count`, `result`)
- **Global variables**: lowercase with underscore when needed (e.g., `seg`, `n`)
- **Class names**: Not used in this repository (procedural style)

### Types and Containers
- Use `vector<int>`, `vector<vector<int>>`, `vector<string>` for collections
- Prefer `int` for indices and values (LeetCode constraints use int)
- Avoid `long long` unless necessary for overflow

### Formatting
- Indentation: 2 spaces per level
- Braces: Same-line style for functions, new-line for conditionals
- Spacing: Standard C++ spacing (space after keywords, around operators)

### Code Structure per Problem
Each `.cpp` file should contain:
1. Problem description comment block (Chinese/English)
2. Solution function(s)
3. Optional: `registerTests()` function for automated testing
4. Optional: `gdb_run()` function for manual debugging

Example structure:
```cpp
#include "basic.h"
#include "test.h"
/*
Problem description here...
tag: <algorithm tags>
note: <Chinese explanation of approach>
*/

// Main solution function
ReturnType solutionFunction(vector<Type>& params) {
    return result;
}

// Automated tests (optional)
void registerTests() {
    test_runner.addTest("description", []() {
        EXPECT_EQ(solutionFunction(input), expected);
    });
}
```

### Error Handling
- No exception handling (LeetCode style)
- Return early on invalid conditions
- Use assertions for debugging (optional)

### Comments
- Include problem description and constraints at top
- Add Chinese notes explaining algorithm insights
- Tag algorithm categories: `tag: array binarysearch`, `tag: sort greedy`
- Comment complex logic inline

## Constraints

- C++17 or later (use modern features if helpful)
- No external dependencies beyond standard library
- Self-contained solutions (no shared state between problems)
- LeetCode online judge compatible
- Do not modify `test.h` and `test_runner.cpp`

## Development Workflow

1. Create new file as `src/LC<number>.cpp`
2. Implement solution following patterns above
3. Add tests with `registerTests()` function
4. Run `./scripts/run.sh src/LC<number>.cpp` to test
5. Debug with GDB if needed
6. Commit changes if required
