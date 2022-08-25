class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prod(n, 1);
        int left = 1, right = 1;
        for(int i = 0; i < n-1; i++){
            left *= nums[i];
            right *= nums[n-1-i];
            prod[i+1] *= left;
            prod[n-2-i] *= right;
        }
        return prod;
    }
};