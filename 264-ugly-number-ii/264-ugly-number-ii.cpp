class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n, 1);
        int j = 0, k = 0, p = 0;
        int a, b, c, d;
        for(int i = 1; i < n; i++){
            a = dp[j] * 2;
            b = dp[k] * 3;
            c = dp[p] * 5;
            d = min(a, min(b, c));
            if(d == a) j++;
            if(d == b) k++;
            if(d == c) p++;
            dp[i] = d;
        }
        return dp[n-1];
    }
};