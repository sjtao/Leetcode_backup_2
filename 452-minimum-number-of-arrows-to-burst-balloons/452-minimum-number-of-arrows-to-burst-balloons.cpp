class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int shot = 1;
        int n = points.size();
        for(int i = 1; i < n; ++i){
            if(points[i][0] <= points[i-1][1]){
                points[i][1] = min(points[i-1][1], points[i][1]);
            }
            else{
                shot++;
            }
        }
        return shot;
    }
};