class Solution {
private:
    const int modu = pow(10, 9) + 7;
public:
    int countVowelPermutation(int n) {
        vector<vector<long>> dp(n, vector<long>(5, 1));
        
        //n = 1: a  e  i   o  u
        //n = 2: e ai aeou iu a
        for(int i = 1; i < n; i++){
            dp[i][0] = dp[i-1][1] % modu;
            dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % modu;
            dp[i][2] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][3] + dp[i-1][4]) % modu;
            dp[i][3] = (dp[i-1][2] + dp[i-1][4]) % modu;
            dp[i][4] = dp[i-1][0] % modu;
        }
        
        long ans = 0;
        for(int i = 0; i < 5; i++)
            ans += dp[n-1][i];
        
        return ans % modu;
    }
};