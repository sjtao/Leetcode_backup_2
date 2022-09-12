class Solution {
private:
    typedef pair<int, pair<int, int>> pi;
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pi> q;
        for(auto p : points){
            int x = p[0];
            int y = p[1];
            int d = x * x + y * y;
            q.push({d, {x, y}});
            if(q.size() > k)
                q.pop();
        }
        
        vector<vector<int>> res;
        while(!q.empty()){
            auto a = q.top().second;
            res.push_back({a.first, a.second});
            q.pop();
        }
        
        return res;
    }
};