/*
 * @lc app=leetcode id=2469 lang=cpp
 *
 * [2469] Convert the Temperature
 */

// @lc code=start
class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        double Kelvin = celsius + 273.15;
        double Fahrenheit = celsius * 1.80 + 32.00;
        return {Kelvin, Fahrenheit};
    }
};
// @lc code=end

