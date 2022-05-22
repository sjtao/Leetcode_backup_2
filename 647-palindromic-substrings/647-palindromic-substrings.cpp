class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++){
            dp[i][i] = 1;
        }
        
        for(int i = 0; i < n-1; i++){
            dp[i][i+1] = (s[i] == s[i+1]);
        }
        
        for(int len = 3; len <= n; len++){
            for(int i = 0, j = i+len-1; j < n; i++, j++)
                dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
        }
        
        int num = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++)
                num += dp[i][j];
        }
        
        return num;
    }
};