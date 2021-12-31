/**
Runtime: 406 ms, faster than 8.98% of C++ online submissions for Longest Increasing Subsequence.
Memory Usage: 10.6 MB, less than 13.44% of C++ online submissions for Longest Increasing Subsequence.
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
