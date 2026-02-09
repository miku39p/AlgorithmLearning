/*
Given a string s, sort it in decreasing order based on the frequency of the
characters. The frequency of a character is the number of times it appears in
the string.

Return the sorted string. If there are multiple answers, return any of them.



Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid
answer. Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc"
are valid answers. Note that "cacaca" is incorrect, as the same characters must
be together. Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.


Constraints:

1 <= s.length <= 5 * 105
s consists of uppercase and lowercase English letters and digits.

tag: sort
note: 这题应该比较简单，先分桶，然后用pirority queue 排序，主要学习排序函数写法
auto cmp = [](xx a, xx b){} 默认是最大堆，也就是true 的 排在后面
在sort中 cmp的含义是 a 是否在 b 前面， true 也就是 a 在 b 前面
pq中 a 在 b的前面，但由于是最大堆，所以先读b
decltype(cmp)
*/

#include "basic.h"
#include "test.h"

string frequencySort(string s) {
  auto cmp = [](const pair<char, int>& a, const pair<char, int>& b) {
    return a.second < b.second;
  };

  priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq(
      cmp);

  unordered_map<char, int> hm;

  for (char c : s) {
    hm[c]++;
  }

  for (const auto& entry : hm) {
    pq.push(make_pair(entry.first, entry.second));
  }

  string result = "";
  while (!pq.empty()) {
    pair<char, int> p = pq.top();
    pq.pop();
    result.append(p.second, p.first);
  }

  return result;
}

void registerTests() {
  auto result = frequencySort("tree");
  test_runner.addTest("tree", EXPECT_EQ(result, "eert"));
}
