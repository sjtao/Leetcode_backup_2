class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mn = nums[0], mno;
        int mx = nums[0], mxo;
        int best = nums[0];
        for(int i = 1; i < n; i++){
            mno = mn;
            mxo = mx;
            mx = max(nums[i], max(mno * nums[i], mxo * nums[i]));
            mn = min(nums[i], min(mno * nums[i], mxo * nums[i]));
            best = max(best, max(mx, mn));
        }
        return best;
    }
};