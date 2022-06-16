class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        //1 letter substring
        for(int i = 0; i < n; i++)
            dp[i][i] = true;
        
        //2 letters substring
        for(int i = 1; i < n; i++)
            dp[i-1][i] = dp[i-1][i-1] && (s[i-1] == s[i]);
        
        //longer substring
        for(int i = n-3; i >= 0; i--){
            for(int j = i+2; j < n; j++){
                dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
            }
        }
        
        int mn = -1, a, b;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(dp[i][j] && mn < j-i+1){
                    mn = j-i+1;
                    a = i;
                }
            }
        }
        
        return s.substr(a, mn);
    }
};