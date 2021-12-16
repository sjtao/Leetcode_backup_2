/**
Runtime: 154 ms, faster than 17.74% of C++ online submissions for Coin Change.
Memory Usage: 14.5 MB, less than 48.32% of C++ online submissions for Coin Change.
*/
class Solution {
public: 
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        int n = coins.size();
        vector<int> dp(amount+1,amount+1);
        dp[0] = 0;
        for(int i = 0; i <= amount; i++){
            for(int j = 0; j < n; j++){
                if(coins[j] <= i){
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
