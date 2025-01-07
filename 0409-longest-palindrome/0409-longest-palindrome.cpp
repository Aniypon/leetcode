class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> a; 

        for(char c: s){
            a[c]++;
        }

        int ans =0;
        bool hasOdd=0;

        for (auto& d: a){
            int freq = d.second;
            if (freq %2 ==0){
                ans += freq;
            }
            else{
                ans += freq -1;
                hasOdd = 1;
            }
        }

        if (hasOdd){
            return ans +1;
        }
        else{
            return ans;
        }
    }
};