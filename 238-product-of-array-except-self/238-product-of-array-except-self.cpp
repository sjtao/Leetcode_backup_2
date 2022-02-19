class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1);
        vector<int> left(n, 1), right(n,1);
        
        for(int i = 1; i < n; ++i){
            left[i] = left[i-1] * nums[i-1];
            right[n-1-i] = right[n-i] * nums[n-i];
        }
        
        for(int i = 0; i < n; i++){
            ans[i] = left[i] * right[i];
        }
        
        return ans;
    }
};