class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> count(10001, 0);
        for(int n : nums)
            count[n]++;
        
        vector<int> dp(10001, 0);
        dp[0] = 0;
        dp[1] = max(count[1]*1, dp[0]);
        for(int i = 2; i <10001; i++){
            dp[i] = max(dp[i-2] + count[i] * i, dp[i-1]);
        }
        
        return dp[10000];
    }
};