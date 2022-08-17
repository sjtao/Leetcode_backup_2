class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        //merge
        set<pair<int,int>> st;
        int n = points.size();
        int xs = points[0][0], xe = points[0][1];
        for(int i = 1; i < n; i++){
            if(points[i][0] > xe){
                st.insert({xs, xe});
                xs = points[i][0];
                xe = points[i][1];
            }
            else{
                xs = max(xs, points[i][0]);
                xe = min(xe, points[i][1]);
            }
        }
        return st.size() + 1;
    }
};