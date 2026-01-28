#include "basic.h"
/*
Suppose an array of length n sorted in ascending order is rotated between 1 and
n times. For example, the array nums = [0,1,4,4,5,6,7] might become:

[4,5,6,7,0,1,4] if it was rotated 4 times.
[0,1,4,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in
the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums that may contain duplicates, return the
minimum element of this array.

You must decrease the overall operation steps as much as possible.



Example 1:

Input: nums = [1,3,5]
Output: 1
Example 2:

Input: nums = [2,2,2,0,1]
Output: 0


Constraints:

n == nums.length
1 <= n <= 5000
-5000 <= nums[i] <= 5000
nums is sorted and rotated between 1 and n times.
tag: array binarysearch
note:这里就是求最小值，因为是排好序，所以无论怎么转必然是左边比中点大右边比中点小，一开始想要这个条件判单，但是还要加上边界检查，会很复杂
起始只要扫一遍l>=r 之后的l就是要找的那个值，另外为了不爆掉int
使用l+(r-l)/2的方法求中点。另外还要注意边界。
*/
int findMin(vector<int>& nums) {
  int n = nums.size();
  if (n == 1) {
    return nums[0];
  }
  int l = 0;
  int r = n - 1;

  while (l < r) {
    int mid = l + (r - l) / 2;
    // 初始版本
    // if (mid == 0 || mid == n - 1 ||
    //     (nums[mid] <= nums[mid + 1] && nums[mid - 1] >= nums[mid])) {
    //   return nums[mid];
    // }
    // in right
    if (nums[mid] > nums[r]) {
      l = mid + 1;
    }
    // in left
    else if (nums[mid] < nums[r]) {
      r = mid;
    } else {
      r -= 1;
    }
  }
  return nums[l];
}

int main() {
  vector<int> a{3, 1};
  findMin(a);
}