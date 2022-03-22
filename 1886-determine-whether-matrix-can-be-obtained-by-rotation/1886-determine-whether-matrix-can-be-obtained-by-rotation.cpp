class Solution {
public:
    
    bool findRotation(vector<vector<int>>& matrix, vector<vector<int>>& target) {
        int n = matrix.size();
        vector<bool> R(4, true);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] != target[i][j]) R[0] = false;
                if(matrix[i][j] != target[n-1-j][i]) R[1] = false;
                if(matrix[i][j] != target[j][n-1-i]) R[2] = false;
                if(matrix[i][j] != target[n-1-i][n-1-j]) R[3] = false;
            }
        }
        return R[0]||R[1]||R[2]||R[3];
    }
};