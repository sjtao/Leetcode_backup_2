class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> r(10001, 0);
        for(int n : nums)
            r[n]+=n;
        
        vector<int> dp(10001, 0);
        dp[0] = r[0];
        dp[1] = r[1];
        for(int i = 2; i < 10001; ++i){
            dp[i] = max(dp[i-1], dp[i-2]+r[i]);
        }
        
        return dp.back();
    }
};