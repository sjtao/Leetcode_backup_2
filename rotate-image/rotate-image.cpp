class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 1) return;
        
        //transpose about (i,i) diagonal
        for(int r = 0; r < n; ++r){
            for(int c = 0; c < r; c++){
                int t = matrix[r][c];
                matrix[r][c] = matrix[c][r];
                matrix[c][r] = t;
            }
        }
        //switch cols i, n-1-i,
        for(int c = 0; c < n/2; c++){
            for(int r = 0; r < n; r++){
                int t = matrix[r][c];
                matrix[r][c] = matrix[r][n-1-c];
                matrix[r][n-1-c] = t;
            }
        }
        
        return;
    }
};