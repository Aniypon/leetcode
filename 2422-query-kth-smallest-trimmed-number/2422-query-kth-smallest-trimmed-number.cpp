class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int numL = nums[0].length();

        for(auto& q: queries){
            vector<pair<string, int>> newN;

            for(int i =0; i < nums.size(); i++){
                newN.push_back({nums[i].substr(numL-q[1]),i});
            }

            sort(newN.begin(), newN.end());
            ans.push_back(newN[q[0]-1].second);
        }

        return ans;
        
    }
};