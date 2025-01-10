class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;

        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;

        for(vector<int> c: points){
            int x = c[0], y = c[1];
            minHeap.push({x*x+y*y, x, y});
        }

        while (k > 0){
            vector<int> top = minHeap.top();
            ans.push_back({top[1], top[2]});
            minHeap.pop();
            k--;
        }

        return ans;
    }
};