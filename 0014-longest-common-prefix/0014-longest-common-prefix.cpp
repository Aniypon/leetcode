class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string sub_str = strs[0];
        int sub_len = sub_str.length();

        for(int i = 1; i < strs.size(); i++){
            string s = strs[i];
            while (sub_str != s.substr(0, sub_len)){
                sub_len--;
                if (sub_len == 0){
                    return "";
                }
                sub_str = sub_str.substr(0, sub_len);
            }
        }
        return sub_str;
    }
};