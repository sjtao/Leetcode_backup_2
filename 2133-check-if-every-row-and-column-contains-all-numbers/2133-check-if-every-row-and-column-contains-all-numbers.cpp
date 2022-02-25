class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<bool>> row(n, vector<bool>(n, false));
        vector<vector<bool>> col(n, vector<bool>(n, false));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                int m = matrix[i][j] - 1;
                if(row[i][m] || col[j][m])
                    return false;
                row[i][m] = true;
                col[j][m] = true;
            }
        }
        return true;
    }
};