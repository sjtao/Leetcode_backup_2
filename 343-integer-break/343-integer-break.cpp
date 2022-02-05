class Solution {
public:
    int integerBreak(int n) {
        int mx = INT_MIN;
        for(int k = 2; k <= n/2+1; k++){
            int dp = 1;
            int q = n / k;
            int r = n % k;
            dp *= pow(q, k-r);
            dp *= pow(q+1, r);
            mx = max(mx, dp);
        }
        return mx;
    }
};