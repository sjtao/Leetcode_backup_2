class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++)
            dp[0][i] = matrix[0][i];
        
        for(int j = 1; j < n; j++){
            for(int k = 0; k < n; k++){
                int a = dp[j-1][k];
                int b = k > 0 ? dp[j-1][k-1] : INT_MAX;
                int c = k < n-1 ? dp[j-1][k+1] : INT_MAX;
                dp[j][k] = matrix[j][k] + min(a, min(b, c));
            }
        }
        
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};