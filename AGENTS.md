# AGENTS.md - LeetCode C++ Repository Guidelines

This is a C++ LeetCode solution repository. All agents should follow these guidelines.

## Build, Lint, and Test Commands

### Quick Test (Recommended)
```bash
# Compile and run tests automatically
./run <file.cpp>

# Example
./run LC154.cpp
```

### Manual Compilation
```bash
# Compile a single solution file
./compile.sh <file.cpp>

# Or manually compile
g++ <file.cpp> -g -o build/main

# Run the compiled binary
./build/main
```

### Debugging (GDB)
- VSCode configured with C++ debugger in `.vscode/launch.json`
- Launch debugger: `F5` in VSCode or run gdb directly:
```bash
gdb ./build/main
```

### No Linting/Formatting Tools
- No ESLint, Prettier, or clang-format configured
- Use the test framework for automated testing

## Automated Testing System

### Overview
The repository uses a simple test framework (`test.h`) with a runner script (`./run`).

### File Structure for Tests
Each `.cpp` file can optionally include test code:

```cpp
#include "basic.h"
#include "test.h"

// Your solution function
int calc(int x, int y) {
  return x + y;
}

// Register tests
void registerTests() {
  test_runner.addTest("description", []() {
    EXPECT_EQ(calc(3, 5), 8);
  });

  test_runner.addTest("another test", []() {
    EXPECT_EQ(calc(-1, 1), 0);
  });
}
```

### Test Framework API

**Registering Tests:**
```cpp
test_runner.addTest("test name", []() {
  // test code
});
```

**Assertions:**
```cpp
EXPECT_EQ(actual, expected);     // Assert equality
EXPECT_TRUE(condition);          // Assert condition is true
```

**Test Output:**
- `[PASS] test name` - Test succeeded
- `[FAIL] test name: message` - Test failed with message
- Summary: "X passed, Y failed"

### How `./run` Works
1. Takes a `.cpp` file as argument
2. Checks for `#include "test.h"`
3. Compiles `file.cpp` + `test_runner.cpp` together
4. Runs the compiled binary
5. Executes all tests registered via `registerTests()`

### Example Test File (a.cpp)
See `/home/zhang/leetcode/a.cpp` for a complete example with multiple test cases.

## Code Style Guidelines

### File Organization
- Each LeetCode problem in a separate file: `LC<number>.cpp` (e.g., `LC154.cpp`)
- Use `basic.h` for common includes (`#include "basic.h"`)
- All source files in repository root directory

### Includes and Headers
```cpp
#include "basic.h"  // Required in every file
```
`basic.h` includes: `<math.h>`, `<algorithm>`, `<map>`, `<string>`, `<vector>`

### Naming Conventions
- **Functions**: camelCase (e.g., `findMin`, `checkPossibility`, `reconstructQueue`)
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
- See existing files (LC154.cpp, LC406.cpp) for reference patterns

### Code Structure per Problem
Each `.cpp` file should contain:
1. Problem description comment block (Chinese/English)
2. Solution function(s)
3. Optional: `registerTests()` function for automated testing
4. Optional: `main()` function for manual testing

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
    // Implementation
    return result;
}

// Helper functions (if needed)
ReturnType helperFunction(...) {
    // ...
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
- Add Chinese notes explaining algorithm insights (existing pattern)
- Tag algorithm categories: `tag: array binarysearch`, `tag: sort greedy`
- Comment complex logic inline

### Algorithm Documentation
Each solution should have:
- Time/Space complexity analysis
- Algorithm approach summary
- Edge cases considered
- Reference to similar problems (optional)

## Development Workflow

1. Create new file as `LC<number>.cpp`
2. Implement solution following patterns above
3. Add tests with `registerTests()` function
4. Run `./run LC<number>.cpp` to test
5. Debug with GDB if needed
6. Commit changes if required

## Constraints

- C++17 or later (use modern features if helpful)
- No external dependencies beyond standard library
- Self-contained solutions (no shared state between problems)
- LeetCode online judge compatible
- Do not modify test.h and test_runner.cpp
