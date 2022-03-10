class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        if((m == r && n == c) || m*n != r*c) return mat;
        
        vector<vector<int>> ans(r, vector<int>(c));
        int idx = 0;
        for(int i = 0; i < r; ++i){
            for(int j = 0; j < c; ++j){
                ans[i][j] = mat[idx/n][idx%n];
                idx ++;
            }
        }
        return ans;
    }
};