/**
Runtime: 20 ms, faster than 87.20% of C++ online submissions for Product of Array Except Self.
Memory Usage: 24 MB, less than 79.64% of C++ online submissions for Product of Array Except Self.
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        ans[0] = 1;
        for(int i = 1; i < n; i++)
            ans[i] = ans[i-1] * nums[i-1];
        
        int r = 1;
        for(int i = n-1; i >= 0; i--){
            ans[i] *= r;
            r *= nums[i];
        }
            
        
        return ans;
    }
};
