/**
Runtime: 152 ms, faster than 81.25% of C++ online submissions for K Closest Points to Origin.
Memory Usage: 53.5 MB, less than 69.00% of C++ online submissions for K Closest Points to Origin.
*/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //max-heap
        priority_queue<pair<int, int>> pq;
        int ds;
        for(int i = 0; i < points.size(); i++){
            ds = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            pq.push(make_pair(ds, i));
            if(pq.size()>k) pq.pop();
        }
        
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        
        return ans;
    }
};
