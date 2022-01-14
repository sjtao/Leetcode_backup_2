class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> qe;
        
        for(int i = 0; i < points.size(); i++){
            int d = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            qe.push({d, {points[i][0], points[i][1]}});
        }
        
        vector<vector<int>> ans(k, vector<int>(2));
        for(int i = 0; i < k; i++){
            auto q = qe.top(); qe.pop();
            ans[i][0] = q.second.first;
            ans[i][1] = q.second.second;
        }
        return ans;
    }
};