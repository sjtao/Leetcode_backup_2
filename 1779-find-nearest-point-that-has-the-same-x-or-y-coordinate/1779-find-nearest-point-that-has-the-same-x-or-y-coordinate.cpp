class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int n = points.size();
        int small = INT_MAX;
        int id = -1;
        for(int i = 0; i < n; ++i){
            if(points[i][0] == x || points[i][1] == y){
                int dis = abs(x-points[i][0]) + abs(y-points[i][1]);
                if(dis < small){
                    small = dis;
                    id = i;
                }
            }
        }
        
        
        return id;
    }
};