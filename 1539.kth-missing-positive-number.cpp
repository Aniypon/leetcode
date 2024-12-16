/*
 * @lc app=leetcode id=1539 lang=cpp
 *
 * [1539] Kth Missing Positive Number
 */

// @lc code=start
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int ind = 0, ans = 1, n = arr.size();
        int count = 0;
        while (count != k) {
            if ((ind < n && ans < arr[ind]) or ind >= n) count++;
            if (ind < n && ans == arr[ind]) ind++;
            ans++;
        }
        return ans-1;
    }
};
// @lc code=end

