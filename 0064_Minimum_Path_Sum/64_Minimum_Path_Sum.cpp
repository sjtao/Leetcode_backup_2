/**
Runtime: 8 ms, faster than 83.32% of C++ online submissions for Minimum Path Sum.
Memory Usage: 10.2 MB, less than 23.17% of C++ online submissions for Minimum Path Sum.
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        dp[0][0] = grid[0][0];
        for(int i = 1; i < n; i++){
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }
        for(int i = 1; i < m; i++){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
};

/**
Runtime: 8 ms, faster than 83.23% of C++ online submissions for Minimum Path Sum.
Memory Usage: 9.7 MB, less than 67.16% of C++ online submissions for Minimum Path Sum.
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = 1; i < n; i++){
            grid[0][i] += grid[0][i-1];
        }
        for(int i = 1; i < m; i++){
            grid[i][0] += grid[i-1][0];
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        
        return grid[m-1][n-1];
    }
};
