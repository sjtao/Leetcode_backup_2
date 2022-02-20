class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[1], nums[0]);
        
        int dp = nums[0];
        int dp1 = max(nums[1], nums[0]);
        int cur = 0;
        for(int i = 2; i < n; ++i){
            cur = max(dp + nums[i], dp1);
            dp = dp1;
            dp1 = cur;
        }
        return dp1;
    }
};