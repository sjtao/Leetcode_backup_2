class Solution {
public:

    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++){
            dp[i][i] = 1;
        }
            
        for(int i = 0; i < n-1; i++){
            if(s[i] == s[i+1])
                dp[i][i+1] = 1;
        }
        
        for(int i = n-3; i >= 0; i--){
            for(int j = i+2; j < n; j++){
                dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
            }
        }
        
        int ms, len = -1;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(dp[i][j] == 1 && j - i + 1> len){
                    len = j-i+1;
                    ms = i;
                }
            }
        }
        
        return s.substr(ms, len);
    }
        
};