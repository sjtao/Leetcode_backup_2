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

/**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for House Robber II.
Memory Usage: 7.9 MB, less than 35.76% of C++ online submissions for House Robber II.
*/
class Solution {
public:
    int n;
    int helper(vector<int>& nums, int s, int e){
        vector<int> dp(n, 0);
        dp[s] = nums[s];
        dp[s+1] = max(nums[s], nums[s+1]);
        for(int i = s+2; i < e; i++){
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp[e-1];
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        return max(helper(nums, 0, n-1), helper(nums, 1, n));
    }
};
