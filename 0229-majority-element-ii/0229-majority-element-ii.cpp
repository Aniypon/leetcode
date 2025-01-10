class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    unordered_map<int, int> m;
    
    for (int num : nums) {
        if (m.find(num) != m.end()) {
            m[num]++;
        } else if (m.size() < 3) {
            m[num] = 1;
        } else {
            for (auto it = m.begin(); it != m.end();) {
                if (it->second == 1) {
                    it = m.erase(it);
                } else {
                    it->second--;
                    ++it;
                }
            }
        }
    }

    unordered_map<int, int> n;
    for (int num : nums) {
        if (n.find(num) != n.end()) {
            n[num]++;
        } else if (m.find(num) != m.end()) {
            n[num] = 1;
        }
    }

    vector<int> ans;
    for (auto& entry : n) {
        if (entry.second > nums.size() / 3) {
            ans.push_back(entry.first);
        }
    }

    return ans;
}

};