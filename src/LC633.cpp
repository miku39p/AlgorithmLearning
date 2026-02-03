#include "basic.h"
#include "test.h"
/*
Given a non-negative integer c, decide whether there're two integers a and b
such that a2 + b2 = c.



Example 1:

Input: c = 5
Output: true
Explanation: 1 * 1 + 2 * 2 = 5
Example 2:

Input: c = 3
Output: false


Constraints:

0 <= c <= 231 - 1
tag: two pointers
note: 这题是经典双指针问题，比较简单，主要是要注意int*int 会爆掉，要么使用long,
要么改成diff减法形式。
*/

bool judgeSquareSum(int c) {
  int max = static_cast<int>(std::sqrt(c));
  int min = 0;
  while (min <= max) {
    int diff = c - max * max - min * min;
    if (diff == 0) {
      return true;
    }
    if (diff > 0) {
      min += 1;
    } else {
      max -= 1;
    }
  }
  return false;
}

void registerTests() {
  test_runner.addTest("5=true", EXPECT_EQ(judgeSquareSum(5), true));
  test_runner.addTest("3=false", EXPECT_EQ(judgeSquareSum(3), false));
  test_runner.addTest("2147482647=false",
                      EXPECT_EQ(judgeSquareSum(2147482647), false));
}
