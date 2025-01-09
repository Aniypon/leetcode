//Time complexity: O(n)
//Space complexity: O(1)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l =0;
        int maxLen = 0;
        unordered_set<char> a;

        for(int r= 0; r < s.length(); r++){
            while (a.find(s[r])!= a.end()){
                a.erase(s[l]);
                l++;
            }

            a.insert(s[r]);
            maxLen = max(maxLen, r-l+1);
        }

        return maxLen;
    }
};