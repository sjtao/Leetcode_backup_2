class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //1. transpose (i,j) ->(j,i)
        //2. reverse per row
        
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                int t = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = t;
            }
        }
        
        for(int i = 0; i < n; ++i){
            reverse(matrix[i].begin(), matrix[i].end());
        }
        
        return;
    }
};