class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(4, 0));
        
        int mx = 0;
        for(int i = 0; i < m; i++){
            int old = 0;
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 1){
                    dp[j][0] = j > 0 ? dp[j-1][0]+1 : 1; //horizontal
                    dp[j][1] = i > 0 ? dp[j][1]+1 : 1; //vertical
                    int prev = dp[j][2];
                    dp[j][2] = i > 0 && j > 0 ? old+1 : 1; //diagonal
                    old = prev;
                    dp[j][3] = i > 0 && j < n-1 ? dp[j+1][3]+1 : 1; //anti-diagonal
                    mx = max(mx, *max_element(dp[j].begin(), dp[j].end()));
                }
                else{
                    old = dp[j][2];
                    for(int k = 0; k < 4; k++)
                        dp[j][k] = 0;
                }
            }
        }
        return mx;
    }
};