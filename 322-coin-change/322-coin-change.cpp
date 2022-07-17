class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for(int a = 1; a <= amount; a++){
            int m = amount+1;
            for(int c : coins){
                if(c <= a){
                    dp[a] = min(dp[a], dp[a-c]+1);
                }
            }
        }
        return dp[amount] == amount+1 ? -1 : dp[amount];
    }
};