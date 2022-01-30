class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mn = 1, mx = 1;
        int mno, mxo;
        int best = INT_MIN;
        for(int n : nums){
            mno = mn;
            mxo = mx;
            mn = min(min(mno * n, mxo *n), n);
            mx = max(max(mno * n, mxo *n), n);
            best = max(mx, best);
        }
        return best;
    }
};