class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.length()-1;
        while (l <= r){
            if (!isalnum(s[l])){
                l++;
            } else if(!isalnum(s[r])){
                r--;
            }
            else{
                char t1 = tolower(s[l]), t2 = tolower(s[r]);
                if (t1 != t2){
                    return false;
                }
                l++;
                r--;
            }
        }

        return true;
    }
};