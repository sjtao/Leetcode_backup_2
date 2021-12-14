/**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for House Robber II.
Memory Usage: 8 MB, less than 36.45% of C++ online submissions for House Robber II.
*/


class Solution {
private:
    vector<int> Nm;
public:
    int robHelper(vector<int>& nums, int l, int r){
        vector<int> dp(r-l+1, 0);
        dp[0] = nums[l];
        dp[1] = max(nums[l], nums[l+1]);
        for(int i = 2; i <= r-l; i++){
            dp[i] = max(dp[i-1], dp[i-2]+nums[i+l]);
        }
        return dp[r-l];
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        
        int r1 = robHelper(nums, 0, n-2);
        int r2 = robHelper(nums, 1, n-1);
        return max(r1, r2);
    }
};
