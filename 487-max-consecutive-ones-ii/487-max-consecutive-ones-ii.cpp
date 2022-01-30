class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        int mx = 1;
        //dp: save ones(left) + ones(right)
        int count = 0;
        for(int i = 0; i < n; i++){
            dp[i] = count;
            count = nums[i] == 0 ? 0 : count+1;
            mx = max(mx, count);
        }
        count = 0;
        for(int i = n-1; i >= 0; i--){
            dp[i] += count;
            count = nums[i] == 0 ? 0 : count+1;
        }
        
        //max for nums[i] == 0
        
        for(int i = 0; i < n; i++){
            if(nums[i] == 0)
                mx = max(mx, dp[i]+1);
        }
        
        return mx;
    }
};