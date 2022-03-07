class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {

        vector<int> md;
        int small = INT_MAX;
        for(auto p : points){
            if(p[0] == x || p[1] == y){
                int d = abs(x-p[0]) + abs(y-p[1]);
                md.push_back(d);
                small = min(d, small);
            }      
            else
                md.push_back(-1);
        }
        
        for(int i = 0; i < md.size(); ++i){
            if(md[i] == small)
                return i;
        }
        
        return -1;
    }
};