class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; i++){
            for (int j = 1; j < m; j++){
                matrix[i][j] ^= matrix[i][j-1];
            }
        }

        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                matrix[i][j] ^= matrix[i-1][j];
            }
        }

        vector<int> ans;

        for(int i =0; i<n; i++){
            for (int j =0; j < m; j++){
                ans.push_back(matrix[i][j]);
            }
        }

        sort(ans.rbegin(), ans.rend());

        return ans[k-1];
    }
};