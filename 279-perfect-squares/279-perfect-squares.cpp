class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        int sn = (int)sqrt(n)+1;
        vector<int> sq(sn);
        for(int i = 0; i < sn; i++){
            sq[i]=i*i;
        }
        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            for(int s = 1; s < sn; s++){
                if(i < sq[s]) break;
                dp[i] = min(dp[i], dp[i-sq[s]]+1);
            }
        }
        return dp[n];
    }
};