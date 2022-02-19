class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1);
        int left = 1, right = 1;
        
        for(int i = 1; i < n; ++i){
            left = left * nums[i-1];
            right = right * nums[n-i];
            ans[i] *= left;
            ans[n-1-i] *= right;
        }
        
        return ans;
    }
};