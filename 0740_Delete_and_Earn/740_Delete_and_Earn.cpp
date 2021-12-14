/***/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        //1 <= nums[i] <= 10^4
        vector<int> nsum(10001, 0);
        for(int n:nums)
            nsum[n] += n;
        
        vector<int> dp(10001, 0);
        dp[0] = nsum[0];
        dp[1] = max(nsum[0], nsum[1]);
        for(int i = 2; i < 10001; i++){
            dp[i] = max(dp[i-1], dp[i-2]+nsum[i]);
        }
        return dp[10000];
    }
};
