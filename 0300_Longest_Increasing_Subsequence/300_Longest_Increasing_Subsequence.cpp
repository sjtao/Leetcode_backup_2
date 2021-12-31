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


/**
Runtime: 20 ms, faster than 64.31% of C++ online submissions for Longest Increasing Subsequence.
Memory Usage: 10.4 MB, less than 62.87% of C++ online submissions for Longest Increasing Subsequence.
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i = 1; i < n; i++){
            if(nums[i] > ans.back())
                ans.push_back(nums[i]);
            else{
                auto it = lower_bound(ans.begin(), ans.end(),nums[i]); 
                //find the 1st element that does not less than val
                *it = nums[i];
            }
        }
        return ans.size();
    }
};
