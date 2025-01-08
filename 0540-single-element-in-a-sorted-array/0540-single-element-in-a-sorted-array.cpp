class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size()-1, mid;
        while (l < r){
            mid = (r-l)/2 + l;

            if (mid % 2 != 0){
                mid --;
            }

            if (nums[mid] != nums[mid+1]){
                r = mid;
            }
            else{
                l = mid +2;
            }
        }
        return nums[l];
    }
};