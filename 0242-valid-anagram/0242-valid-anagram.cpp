class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        unordered_map<char,int> a,b;

        for (int i =0; i < s.length(); i++){
            a[s[i]] +=1;
            b[t[i]] +=1;
        }

        return a==b;

    }
};