class Solution {
public:
    int integerBreak(int n) {
        int dp;
        int mx = 1; //k=n
        for(int k = 2; k <= n/2+1; k++){
            dp = 1;
            int res = n / k;
            int mod = n % k;
            dp *= pow(res, k - mod);
            dp *= pow(res+1, mod);
            mx = max(mx, dp);
        }
        
        return mx;
    }
};