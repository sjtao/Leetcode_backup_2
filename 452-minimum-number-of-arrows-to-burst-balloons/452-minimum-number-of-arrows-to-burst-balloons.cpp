class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        vector<vector<int>> dup;
        int n = points.size();
        int start = points[0][0], end = points[0][1];
        for(int i = 1; i < n; i++){
            if(points[i][0] <= end){
                start = max(start, points[i][0]);
                end = min(end, points[i][1]);
            }
            else{
                dup.push_back({start, end});
                start = points[i][0];
                end = points[i][1];
            }
        }
        dup.push_back({start, end});
        return dup.size();
    }
};