class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        int mn = 1, mno;
        int mx = 1, mxo;
        int mxb = INT_MIN;
        
        for(int i = 0; i < n; i++){
            mno = mn;
            mxo = mx;
            mn = min(min(mno * nums[i], mxo * nums[i]), nums[i]);
            mx = max(max(mno * nums[i], mxo * nums[i]), nums[i]);
            mxb = max(mxb, mx);
        }
        
        return mxb;
    }
};