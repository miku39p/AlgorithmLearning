#include "basic.h"
#include "test.h"
/*
You are given an array of people, people, which are the attributes of some
people in a queue (not necessarily in order). Each people[i] = [hi, ki]
represents the ith person of height hi with exactly ki other people in front who
have a height greater than or equal to hi.

Reconstruct and return the queue that is represented by the input array people.
The returned queue should be formatted as an array queue, where queue[j] = [hj,
kj] is the attributes of the jth person in the queue (queue[0] is the person at
the front of the queue).



Example 1:

Input: people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
Output: [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
Explanation:
Person 0 has height 5 with no other people taller or the same height in front.
Person 1 has height 7 with no other people taller or the same height in front.
Person 2 has height 5 with two persons taller or the same height in front, which
is person 0 and 1. Person 3 has height 6 with one person taller or the same
height in front, which is person 1. Person 4 has height 4 with four people
taller or the same height in front, which are people 0, 1, 2, and 3. Person 5
has height 7 with one person taller or the same height in front, which is
person 1. Hence [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]] is the reconstructed
queue. Example 2:

Input: people = [[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]]
Output: [[4,0],[5,0],[2,2],[3,2],[1,4],[6,0]]


Constraints:

1 <= people.length <= 2000
0 <= hi <= 106
0 <= ki < people.length
It is guaranteed that the queue can be reconstructed.

tag: sort greedy
note:
最先是想着从大到小排，然后发现大的插好之后，小的可以插很多地方，有好多情况，这时候应该要想到倒过来，从小到大排序。
一开始想着按照p[1]是第几个就插到第几个，因为想着已经是最矮了，所以前面必须要满足，后来发现【5，0】【6，1】
这个就已经不对了，主要原因是插入6，1时候有个潜在的条件是前面必须要有1个空的来插入比他高的，所以后面改成了，
按照位置从头检查一遍，直到满足空着的大于这个数字。
*/
int n;
vector<int> seg;

void build(int i, int l, int r) {
  if (l == r) {
    seg[i] = 1;
    return;
  }

  int mid = l + (r - l) / 2;

  build(2 * i + 1, l, mid);
  build(2 * i + 2, mid + 1, r);

  seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
}

void update(int i, int l, int r, int j) {
  if (l == r) {
    seg[i] = 0;
    return;
  }

  int m = l + (r - l) / 2;

  if (j <= m)
    update(2 * i + 1, l, m, j);
  else
    update(2 * i + 2, m + 1, r, j);

  seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
}

int query(int i, int l, int r, int x) {
  if (l == r) return l;

  int m = l + (r - l) / 2;
  if (x <= seg[2 * i + 1])
    return query(2 * i + 1, l, m, x);
  else
    return query(2 * i + 2, m + 1, r, x - seg[2 * i + 1]);
}

vector<vector<int>> reconstructQueue_best_copy(vector<vector<int>>& people) {
  n = people.size();
  seg.resize(4 * n);
  vector<vector<int>> ans(n);

  sort(people.begin(), people.end(), [](auto& x, auto& y) {
    if (x[0] == y[0]) return x[1] > y[1];

    return x[0] < y[0];
  });

  build(0, 0, n - 1);

  for (auto& x : people) {
    int pos = x[1] + 1;
    int idx = query(0, 0, n - 1, pos);
    ans[idx] = x;
    update(0, 0, n - 1, idx);
  }
  return ans;
}

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
  sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) {
    if (a[0] < b[0]) {
      return true;
    } else if (a[0] == b[0]) {
      return a[1] >= b[1];
    } else
      return false;
  });
  vector<vector<int>> result(people.size(), {-1, -1});
  for (auto i = 0; i < people.size(); i++) {
    auto& p = people[i];
    int count = p[1];
    for (int j = 0; j < people.size(); j++) {
      // means this slot is empty
      if (result[j][1] == -1) {
        count -= 1;
      }
      if (count < 0) {
        result[j][0] = p[0];
        result[j][1] = p[1];
        break;
      }
    }
  }
  return result;
}

void registerTests() {
  vector<vector<int>> input1 = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
  vector<vector<int>> expected1 = {{5, 0}, {7, 0}, {5, 2},
                                   {6, 1}, {4, 4}, {7, 1}};
  auto result1 = reconstructQueue(input1);
  test_runner.addTest("example1", EXPECT_EQ(result1, expected1));
}
