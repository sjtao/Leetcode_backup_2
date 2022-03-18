class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int lmin = INT_MAX;
        int rmax = INT_MIN;
        vector<bool> dp(n, true);
        for(int i = 1; i < n-1; i++){
            lmin = min(lmin, nums[i-1]);
            rmax = max(rmax, nums[n-i]);
            if(lmin < nums[i])
                dp[i] = dp[i] && true;
            else
                dp[i] = dp[i] && false;
            if(rmax > nums[n-1-i]) 
                dp[n-i-1] = dp[n-1-i] && true;
            else
                dp[n-i-1] = dp[n-1-i] && false;
        }
        
        for(int i = 1; i < n-1; i++){
            if(dp[i])
                return true;
        }
            
        return false;
    }
};