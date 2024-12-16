/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
   public:
    bool isPalindrome(int x) {
        if (x < 0 or (x % 10 == 0 and x != 0)) {
            return false;
        }

        int reversedx = 0;
        while (reversedx < x) {
            reversedx = reversedx * 10 + x % 10;
            x /= 10;
        }
        return (x == reversedx or x == reversedx / 10);
    }
};
// @lc code=end
