class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int, pair<int, int>>> q;
        for(auto p : points){
            int d = p[0] * p[0] + p[1] * p[1];
            q.push({d, {p[0], p[1]}});
            if(q.size() > k)
                q.pop();
        }
        while(!q.empty()){
            auto d = q.top();
            ans.push_back({d.second.first, d.second.second});
            q.pop();
        }
        return ans;
    }
};