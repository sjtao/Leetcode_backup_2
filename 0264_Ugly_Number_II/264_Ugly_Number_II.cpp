/**
Runtime: 8 ms, faster than 75.69% of C++ online submissions for Ugly Number II.
Memory Usage: 7.7 MB, less than 64.67% of C++ online submissions for Ugly Number II.
*/

class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 1)
            return n;
        vector<int> dp(n, 1);
        int i = 0, j = 0, k = 0;
        int a, b, c, d;
        for(int p = 1; p < n; p++){
            a = dp[i] * 2;
            b = dp[j] * 3;
            c = dp[k] * 5;
            d = min(a, min(b, c));
            if(d == a) i++;
            if(d == b) j++;
            if(d == c) k++;
            dp[p] = d;
        }
        return dp[n-1];
    }
};
