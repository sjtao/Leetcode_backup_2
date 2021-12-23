/**
Runtime: 8 ms, faster than 98.17% of C++ online submissions for Minimum Falling Path Sum.
Memory Usage: 10.4 MB, less than 13.85% of C++ online submissions for Minimum Falling Path Sum.
*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        
        for(int i = 0; i < n; i++)
            dp[0][i] = matrix[0][i];
        
        int a, b, c;
        for(int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){
                if(j - 1 >= 0) a = dp[i-1][j-1];
                else           a = INT_MAX;
                b = dp[i-1][j];
                if(j + 1 < n)  c = dp[i-1][j+1];
                else           c = INT_MAX;
                dp[i][j] = matrix[i][j] + min(a, min(b, c));
            }
        }
        
        int mi = dp[m-1][0];
        for(int i = 1; i < n; i++)
            mi = min(mi, dp[m-1][i]);
        
        return mi;
    }
};
