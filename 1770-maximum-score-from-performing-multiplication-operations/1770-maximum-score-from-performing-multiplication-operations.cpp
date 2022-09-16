class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        vector<int> dp(m+1, 0);
        vector<int> cp(m+1);
        
        for(int p = m-1; p >= 0; p--){
            cp = dp;
            for(int i = p; i >= 0; i--){
                dp[i] = max(multipliers[p] * nums[i] + cp[i+1], multipliers[p] * nums[n-1-(p-i)] + cp[i]);
            }
            cp.clear();
        }
        
        return dp[0];
    }
};