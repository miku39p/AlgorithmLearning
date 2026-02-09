/*
Given an array nums with n objects colored red, white, or blue, sort them
in-place so that objects of the same color are adjacent, with the colors in the
order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and
blue, respectively.

You must solve this problem without using the library's sort function.



Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]


Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.
tag: sort
note: 这是经典的荷兰国旗算法，low指左边排好的0的部分，所以当mid = 0 时
low+1, mid+1, 左边都排完了，当mid = 1时，mid+=1, 因为可能时正确的，如果后面还有0
那么就和low去交换，如果是2，那就是最大，和 high交换，high的右边排完了，high--
直到mid >= high
*/
#include "basic.h"
#include "test.h"
void sortColors(vector<int>& nums) {
  int high = nums.size() - 1;
  int low{}, mid{};
  while (mid <= high)
    if (nums[mid] == 0)
      swap(nums[mid++], nums[low++]);
    else if (nums[mid] == 1)
      mid++;
    else
      swap(nums[mid], nums[high--]);
}

void registerTests() {
  vector<int> num = {2, 0, 2, 1, 1, 0};
  vector<int> result = {0, 0, 1, 1, 2, 2};
  sortColors(num);
  test_runner.addTest("[2,0,2,1,1,0]", EXPECT_EQ(num, result));
}