class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n+1);
        sum[0] = 0;
        for(int i = 1; i <= n; i++){
            if(target == nums[i-1])
                return 1;
            sum[i] = sum[i-1] + nums[i-1];
        }
        
        int ans = n+1;
        for(int i = 1; i <= n; i++){
            int t = target + sum[i-1];
            auto b = lower_bound(sum.begin(), sum.end(), t);
            if(b != sum.end())
                ans = min(ans, static_cast<int>(b - (sum.begin() + i - 1)));
        }

        return ans == n+1 ? 0 : ans;
    }
};