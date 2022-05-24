class Solution {
public:

    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        for(int i = 0; i < n; i++){
            dp[i][i] = true;
        }
        
        int ms = 0, len = 1;
        for(int i = 0; i < n-1; i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true;
                if(len < 2){
                    len = 2;
                    ms = i;
                }
            }
        }
        
        for(int i = n-3; i >= 0; i--){
            for(int j = i+2; j < n; j++){
                dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
                if(dp[i][j] == true && j - i + 1> len){
                    len = j-i+1;
                    ms = i;
                }
            }
        }
        
        return s.substr(ms, len);
    }
        
};