/**
Runtime: 732 ms, faster than 11.41% of C++ online submissions for Matrix Block Sum.
Memory Usage: 9.4 MB, less than 73.98% of C++ online submissions for Matrix Block Sum.
*/

class Solution {
public:
    int m, n;
    int blocksum(vector<vector<int>>& mat, int i, int j, int k){
        int s = 0;
        for(int r = max(0, i-k); r <= min(i+k, m-1); r++){
            for(int c = max(0, j-k); c <= min(j+k, n-1); c++){
                s += mat[r][c];
            }
        } 
        return s;
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        m = mat.size();
        n = mat[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                dp[i][j] = blocksum(mat, i, j, k);
            }
        }
        
        return dp;        
    }
};
