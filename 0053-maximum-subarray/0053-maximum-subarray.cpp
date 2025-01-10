class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxS = nums[0];
        int curS = 0;

        for (int n: nums){
            if (curS < 0){
                curS = 0;
            }

            curS += n;
            maxS = max(maxS, curS);
        }

        return maxS;
    }
};