class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        vector<int> dp = triangle[rows-1];

        for (int r = rows-2; r >= 0; r--){
            for (int c =0; c <= r; c++){
                dp[c] = min(dp[c], dp[c+1])+triangle[r][c];
            }
        }

        return dp[0];
    }
};