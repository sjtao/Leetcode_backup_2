class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        int n = coins.size();
        dp[0] = 0;
        for(int j = 0; j < n; ++j){
            for(int i = 1; i <= amount; ++i){
                if(i >= coins[j])
                    dp[i] = min(dp[i-coins[j]]+1, dp[i]);
            }
        }
        return dp[amount] == amount+1 ? -1:dp[amount];
    }
};