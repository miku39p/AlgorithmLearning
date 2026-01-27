#include "basic.h"
/*
You are given a string s. We want to partition the string into as many parts as
possible so that each letter appears in at most one part. For example, the
string "ababcc" can be partitioned into ["abab", "cc"], but partitions such as
["aba", "bcc"] or ["ab", "ab", "cc"] are invalid.

Note that the partition is done so that after concatenating all the parts in
order, the resultant string should be s.

Return a list of integers representing the size of these parts.



Example 1:

Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits
s into less parts. Example 2:

Input: s = "eccbbbbdec"
Output: [10]


Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.

tag: string
*/

vector<int> partitionLabels(string s) {
  vector<int> last_position(26, -1);
  int size = s.size();
  for (int i = 0; i < size; i++) {
    char c = s[i];
    last_position[c - 'a'] = i;
  }
  vector<int> result;
  int part_end;
  int cur_i = 0;
  int i;
  while (cur_i < size) {
    i = cur_i;
    part_end = last_position[s[i] - 'a'];
    int part_size = 0;
    for (; i <= part_end; i++) {
      part_size += 1;
      if (last_position[s[i] - 'a'] > part_end) {
        part_end = last_position[s[i] - 'a'];
      }
    }
    cur_i = i;
    result.emplace_back(part_size);
  }
  return result;
}

int main() {
  partitionLabels("ababcbacadefegdehijhklij");
  return 0;
}
