class Solution {
public:
    static bool comp(pair<char,int>& a, pair<char,int>& b){
        return a.second > b.second;
    }

    string frequencySort(string s) {
        unordered_map<char, int> freq;

        for (char c: s){
            freq[c]++;
        }

        vector<pair<char,int>> freqSort(freq.begin(), freq.end());
        sort(freqSort.begin(), freqSort.end(), comp);

        string ans = "";
        for(auto& k: freqSort){
            ans+= string(k.second, k.first);
        }

        return ans;
    }
};