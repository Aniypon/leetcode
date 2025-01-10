class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int down =0, up = matrix.size()-1;

        while (down <= up){
            int mid = (down+up)/2;

            if (matrix[mid][matrix[0].size()-1]<target){
                down = mid +1;
            } else if (matrix[mid][0] > target){
                up = mid -1;
            } else{
                break;
            }
        }

        int row = (down+up)/2;
        int l = 0, r = matrix[row].size()-1;

        while (l<=r){
            int mid = (l+r)/2;
            if (target == matrix[row][mid]){
                return true;
            } else if (target > matrix[row][mid]){
                l = mid +1;
            } else{
                r = mid -1;
            }
        }

        return false;
    }
};