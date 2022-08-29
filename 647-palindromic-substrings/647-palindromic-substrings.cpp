class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n,vector<bool>(n));
        
        for(int i = 0; i < n; i++)
            dp[i][i] = true;
        
        for(int i = 0; i < n-1; i++)
            dp[i][i+1] = (s[i] == s[i+1]);
        
        for(int i = n-3; i >= 0; i--){
            for(int j = i+2; j < n; j++){
                dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
            }
        }
        
        int p = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(dp[i][j])
                    p++;
            }
        }
        
        return p;
    }
};