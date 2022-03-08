class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        int X = coordinates[1][0] - coordinates[0][0];
        int Y = coordinates[1][1] - coordinates[0][1];
        for(int i = 2; i < n; i++){
            if(X*(coordinates[i][1] - coordinates[i-1][1]) != Y * (coordinates[i][0] - coordinates[i-1][0]))
                return false;
        }
        return true;
    }
};