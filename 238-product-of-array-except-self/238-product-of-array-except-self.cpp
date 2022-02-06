class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1);
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        
        //left: 0 - i-1;
        //right: i+1, n-1
        for(int i = 1; i < n; i++){
            left[i] = left[i-1] * nums[i-1];
            right[n-1-i] = right[n-i] * nums[n-i];
            ans[i] *= left[i];
            ans[n-1-i] *= right[n-1-i];
        }
        
        return ans;
    }
};