/*
 * @lc app=leetcode id=540 lang=cpp
 *
 * [540] Single Element in a Sorted Array
 */

// @lc code=start
class Solution {
 public:
  int singleNonDuplicate(vector<int>& nums) {
    int l = 0, r = nums.size()-1;
    while (l < r) {
      int m = l + (r-l) / 2;
      if (m % 2 == 1) {
        m--;
      }
      if (nums[m] != nums[m + 1]) {
        r = m;
      } else {
        l = m + 2;
      }
    }
    return nums[l];
  }
};
// @lc code=end
