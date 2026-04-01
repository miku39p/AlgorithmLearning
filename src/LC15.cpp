/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.



Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not
matter. Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
tags: Array, Two Pointers
*/

#include "basic.h"
#include "test.h"

vector<vector<int>> threeSum(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  vector<vector<int>> res;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] > 0) {
      continue;
    }
    if (i > 0 && nums[i] == nums[i - 1]) {
      continue;
    }
    int left = i + 1;
    int right = nums.size() - 1;
    int target = -nums[i];
    while (left < right) {
      int sum = nums[left] + nums[right];
      if (sum > target) {
        right -= 1;
      } else if (sum == target) {
        while (left < right && nums[left] == nums[left + 1]) left++;
        while (left < right && nums[right] == nums[right - 1]) right--;
        res.push_back({nums[i], nums[left], nums[right]});
        left++;
        right--;
      } else {
        left += 1;
      }
    }
  }
  return res;
}

void gdb_run() {
  vector<int> num = {-1, 0, 1, 2, -1, -4};
  num = {-2, 0, 3, -1, 4, 0, 3, 4, 1, 1, 1, -3, -5, 4, 0};
  auto result = threeSum(num);
}

void registerTests() {
  vector<int> num = {-1, 0, 1, 2, -1, -4};
  vector<vector<int>> result = {{-1, -1, 2}, {-1, 0, 1}};
  auto res = threeSum(num);
  test_runner.addTest("[-1,0,1,2,-1,-4]", EXPECT_EQ(res, result));
}