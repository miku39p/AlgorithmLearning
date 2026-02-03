#include "basic.h"
#include "test.h"
/*
Given a string s, return true if the s can be palindrome after deleting at most
one character from it.



Example 1:

Input: s = "aba"
Output: true
Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
Example 3:

Input: s = "abc"
Output: false


Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
tag: two pointers
note:
这题一开始就想到了用双指针做，然后对于不一样的处理，一开始想着看下一个，哪边的下一个一样就删除哪一个，
然后有个例子不对，发现这个算法有漏洞，当两遍都可以删的时候选择了左边为了弥补这个漏洞于是就看下一个，结果又有不对了
为了弥补这个漏洞花了很长时间，就应该想到直接检查子列就好用递归，不应该死磕
*/

bool val(const string& s, int left, int high) {
  while (left < high) {
    if (s[left] != s[high]) return false;
    left++;
    high--;
  }
  return true;
}

bool validPalindrome(string s) {
  int a = 0;
  int b = s.size() - 1;
  while (a < b) {
    if (s[a] != s[b]) {
      return val(s, a + 1, b) || val(s, a, b - 1);
    }
    a++;
    b--;
  }
  return true;
}

void registerTests() {
  test_runner.addTest("aba=true", EXPECT_EQ(validPalindrome("aba"), true));
  test_runner.addTest("abca=true", EXPECT_EQ(validPalindrome("abca"), true));
  test_runner.addTest("abc=false", EXPECT_EQ(validPalindrome("abc"), false));
  test_runner.addTest("eceec=true", EXPECT_EQ(validPalindrome("eceec"), true));
  test_runner.addTest(
      "ebcbbececabbacecbbcbe=true",
      EXPECT_EQ(validPalindrome("ebcbbececabbacecbbcbe"), true));
}
