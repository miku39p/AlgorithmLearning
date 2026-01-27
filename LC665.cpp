#include "basic.h"
/*
Given an array nums with n integers, your task is to check if it could become
non-decreasing by modifying at most one element.

We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i
(0-based) such that (0 <= i <= n - 2).



Example 1:

Input: nums = [4,2,3]
Output: true
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
Example 2:

Input: nums = [4,2,1]
Output: false
Explanation: You cannot get a non-decreasing array by modifying at most one
element.


Constraints:

n == nums.length
1 <= n <= 104
-105 <= nums[i] <= 105
tag: array greedy
note:
这道题一开始以为很简单，只要判单是否有两次下降趋势就行，结果发现[3,4,2,3]这个例子就不对了，因为3-2中间没有数字可以满足，所以添加了检查左边数字，
后来发现[5,7,1,8]这个例子也不对了，因为i也可以改，不一定只能改左边，所以两种都要检查，外加边界肯定有数字满足，复盘：不能想的太简单，每次总是减少了题目的要求
导致了不等价
*/

bool checkPossibility_beetter_copy(vector<int>& nums) {
  int count = 0;

  for (int i = 1; i < nums.size(); i++) {
    if (nums[i] < nums[i - 1]) {
      count++;
      if (count > 1) return false;

      if (i == 1 || nums[i] >= nums[i - 2]) {
        nums[i - 1] = nums[i];  // lower previous
      } else {
        nums[i] = nums[i - 1];  // raise current
      }
    }
  }

  return true;
}

bool checkPossibility(vector<int>& nums) {
  int decrease_time = 1;
  for (int i = 1; i < nums.size(); i++) {
    if (nums[i] < nums[i - 1]) {
      // check has chance
      if (decrease_time <= 0) {
        return false;
      }
      // check has number
      bool has_number = false;
      // it is border
      if (i == 1 || i == nums.size() - 1) {
        has_number = true;
      }
      // try to change i -1
      else if (nums[i] >= nums[i - 2]) {
        has_number = true;
      }
      // try to change i
      else if (nums[i + 1] >= nums[i - 1]) {
        has_number = true;
      }

      if (has_number) {
        // use chance
        decrease_time -= 1;
      } else {
        return false;
      }
    }
  }
  return true;
}

int main() {
  std::vector<int> a{{3, 4, 2, 3}};
  checkPossibility(a);
  return 0;
}