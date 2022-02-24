class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n, 0);
        dp[n-1] = 1;
        for(int i = n-2; i >= 0; --i){
            for(int j = i+1; j < n && j <= i+nums[i]; j++){
                dp[i] = dp[i] || dp[j];
                if(dp[i] == 1)
                    break;
            }
        }
        return dp[0];
    }
};