class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;

        if (digits.empty()){
            return ans;
        }
        
        unordered_map<char, string> digitToLetters = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        backtrack(digits, 0, "", digitToLetters, ans);

        return ans;
    }

    void backtrack(string& digits, int ind, string temp, unordered_map<char, string>& digitToLetters, vector<string>& ans){
        if(ind == digits.length()){
            ans.push_back(temp);
            return;
        }

        string letters =  digitToLetters[digits[ind]];

        for(char letter: letters){
            backtrack(digits, ind+1, temp + letter, digitToLetters, ans);
        }
    }

    
};