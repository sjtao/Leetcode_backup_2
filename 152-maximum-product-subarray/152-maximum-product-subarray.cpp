class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mn = 1;
        int mx = 1;
        int best = INT_MIN;
        int mno, mxo;
        for(int n : nums){
            mno = mn;
            mxo = mx;
            mn = min(n, min(mno * n, mxo * n));
            mx = max(n, max(mno * n, mxo * n));
            best = max(best, max(mn, mx));
        }
        return best;
    }
};