/**
Runtime: 8 ms, faster than 90.78% of C++ online submissions for Coin Change 2.
Memory Usage: 7.2 MB, less than 79.06% of C++ online submissions for Coin Change 2.
*/

class Solution {
public:

    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1,0);
        //base case: amount = 0
        dp[0] = 1;
        for(int c : coins){
            for(int i = c; i <= amount; i++){
                dp[i] += dp[i-c];
            }
        }
        return dp[amount];
    }
};
