class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return false;
        int sum = 0;
        for(int& a : nums)
            sum += a;
        if(sum % 2) return false;
        int half = sum / 2;
        
        vector<vector<bool>> dp(n+1, vector<bool>(half+1, false));
        dp[0][0] = true;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= half; j++){
                if(j < nums[i-1])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i-1]];
            }
        }
        
        return dp[n][half];
    }
};