class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int best = nums[0];
        int mx = nums[0], mn = nums[0];
        int mxo, mno;
        int n = nums.size();
        for(int i = 1; i < n; i++){
            mxo = mx;
            mno = mn;
            mx = max(nums[i], max(mxo * nums[i], mno * nums[i]));
            mn = min(nums[i], min(mxo * nums[i], mno * nums[i]));
            best = max(best, max(mx, mn));
        }
        return best;
    }
};