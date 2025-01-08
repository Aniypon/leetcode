class Solution {
public:
    static bool comp(string a, string b){
        string s1=a+b, s2=b+a;
        return s1>s2;  
    }
    string largestNumber(vector<int>& nums) {
        vector<string> snums; 
        for(auto num: nums){
            snums.push_back(to_string(num));
        }

        sort(snums.begin(),snums.end(), comp);

        if(snums[0] == "0"){
            return "0";
        }

        string ans = "";

        for(auto s: snums){
            ans += s;
        }

        return ans;   
    }
};