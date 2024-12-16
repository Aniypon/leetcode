/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;

    while (r > l) {
      int m = nums[l] + nums[r];
      if (m == target) {
        return {l + 1, r + 1};
      }
      if (m > target) {
        r--;
      } else {
        l++;
      }
    }
    return {};
  }
};

// @lc code=end
