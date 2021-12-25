/**
Runtime: 72 ms, faster than 31.03% of C++ online submissions for Number of Dice Rolls With Target Sum.
Memory Usage: 8.5 MB, less than 38.73% of C++ online submissions for Number of Dice Rolls With Target Sum.
*/

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));//dp[i][k] as number of ways we can get target using i dices
        dp[0][0] = 1;
        
        int base = pow(10, 9)+7;
        long way = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= k; j++){
                for(int g = j; g <= target; g++){
                    dp[i][g] = (dp[i][g] + dp[i-1][g-j]) % base;
                }
            }
        }
        return dp[n][target];
    }
};
