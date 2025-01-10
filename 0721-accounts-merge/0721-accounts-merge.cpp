class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0); 
        size.resize(n + 1, 0); 
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return; 

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return; 
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& details) {
        int n = details.size();
        DisjointSet ds(n);
        sort(details.begin(), details.end());

        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < details[i].size(); j++) {
                string mail = details[i][j];
                if (mp.find(mail) == mp.end()) {
                    mp[mail] = i;
                } else {
                    ds.unionBySize(i, mp[mail]);
                }
            }
        }


        vector<string> mergelist[n];
        for (auto it : mp) {
            int idx = it.second;
            string mail = it.first;
            int ult_parent = ds.findUPar(idx);
            mergelist[ult_parent].push_back(mail);
        }

        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (mergelist[i].empty()) continue;
            sort(mergelist[i].begin(), mergelist[i].end());
            vector<string> tmp;
            tmp.push_back(details[i][0]); 
            for (int j = 0; j < mergelist[i].size(); j++) {
                tmp.push_back(mergelist[i][j]); 
            }
            ans.push_back(tmp);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};