class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(4, 0)));
        int mx = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 1){
                    dp[i][j][0] = i > 0 ? dp[i-1][j][0]+1 : 1; //horizontal
                    dp[i][j][1] = j > 0 ? dp[i][j-1][1]+1 : 1; //vertical
                    dp[i][j][2] = i > 0 && j > 0 ? dp[i-1][j-1][2]+1 : 1; //diagonal
                    dp[i][j][3] = i > 0 && j < n-1 ? dp[i-1][j+1][3]+1 : 1; //anti-diagonal
                    mx = max(mx, *max_element(dp[i][j].begin(), dp[i][j].end()));
                }
            }
        }
        return mx;
    }
};