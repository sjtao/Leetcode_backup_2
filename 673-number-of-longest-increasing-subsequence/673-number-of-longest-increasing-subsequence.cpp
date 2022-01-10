class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        //len[i]: the length of the Longest Increasing Subsequence which ends with nums[i].
        //cnt[i]: the number of the Longest Increasing Subsequence which ends with nums[i].
        //dp[i] = {len, cnt}  
        vector<pair<int,int>> dp(n,{1,1}); 
        int maxlen = 0, res = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    if(dp[i].first == dp[j].first + 1)
                        dp[i].second += dp[j].second;
                    if(dp[i].first < dp[j].first + 1)
                        dp[i] = {dp[j].first + 1, dp[j].second};
                }
            }
            //nums is not sorted, so cannot garantee nums[end] is included in the subsequence
            //so cannot just return dp[end].second
            if(maxlen == dp[i].first) res += dp[i].second;
            if(maxlen < dp[i].first){
                maxlen = dp[i].first;
                res = dp[i].second;
            }
        }
        
        return res;
        

    }
};