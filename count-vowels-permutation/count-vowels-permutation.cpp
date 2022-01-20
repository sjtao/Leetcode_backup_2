class Solution {
private:
    const int modu = pow(10, 9) + 7;
public:
    int countVowelPermutation(int n) {
        vector<long> dp(5, 1);
        
        //n = 1: a  e  i   o  u
        //n = 2: e ai aeou iu a
        for(int k = 1; k < n; k++){
            long a = dp[0];
            long e = dp[1];
            long i = dp[2];
            long o = dp[3];
            long u = dp[4];
            dp[0] = e % modu;
            dp[1] = (a + i) % modu;
            dp[2] = (a + e + o + u) % modu;
            dp[3] = (i + u) % modu;
            dp[4] = a % modu;
        }
        
        long ans = 0;
        for(int i = 0; i < 5; i++)
            ans += dp[i];
        
        return ans % modu;
    }
};