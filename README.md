# LeetCode C++ Solutions
个人算法练习题仓库，使用 C++ 实现算法题目。

## 目录结构
```
AlgorithmLearning/
├── src/              # 题目解决方案 (LC<number>.cpp)
├── test_frame/       # 测试框架
├── scripts/          # 运行脚本
├── build/            # 编译输出
└── README.md
```

## 脚本说明

### run.sh - 运行单个测试
编译并运行指定文件的测试用例。

```bash
./scripts/run.sh <file.cpp>
./scripts/run.sh LC154.cpp          # 文件名
./scripts/run.sh src/LC406.cpp       # 相对路径
```

### compile.sh - 编译（支持 GDB）
编译文件用于 GDB 调试。

```bash
./scripts/compile.sh <file.cpp>
./scripts/compile.sh src/LC154.cpp
```

### run_all.sh - 运行全部测试
运行 `src/` 下所有 .cpp 文件的测试。

```bash
./scripts/run_all.sh
```

## 快速开始

### 运行单个题目测试

```bash
./scripts/run.sh src/LC154.cpp
```

### 添加新题目

1. 在 `src/` 目录下创建新文件 `LC<number>.cpp`
2. 按以下模板编写：

```cpp
#include "basic.h"
#include "test.h"
/*
Problem description...

tag: algorithm-category
note: 解题思路说明
*/

ReturnType solutionFunction(vector<Type>& params) {
    return result;
}

void registerTests() {
    test_runner.addTest("description",
        EXPECT_EQ(solutionFunction(input), expected);
    );
}
```

3. 运行测试：
```bash
./scripts/run.sh src/LC<number>.cpp
```

## 测试框架

### 可用断言

- `EXPECT_EQ(actual, expected)` - 断言相等
- `EXPECT_TRUE(condition)` - 断言条件为真

### 手动调试

在代码中添加 `gdb_run()` 函数，然后使用 GDB 调试：

```bash
./scripts/compile.sh src/<file>.cpp
gdb ./build/main
```

## 技术栈

- C++17
- 无外部依赖
- 简洁的单元测试框架
