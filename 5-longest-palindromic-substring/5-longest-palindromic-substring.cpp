class Solution {
public:

    string longestPalindrome(string s) {
        int n = s.length();
        if(n == 1) return s;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int len = 1;
        int start = 0;
        
        for(int i = 0; i < n; i++){
            dp[i][i] = true;
        }
        

        
        for(int i = 0; i < n-1; i++){
            dp[i][i+1] = (s[i] == s[i+1]);
            if(dp[i][i+1]){
                len = 2;
                start = i;
            }
        }
        
        for(int i = n-3; i >= 0; i--){
            for(int j = i+2; j < n; j++){
                dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
                if(dp[i][j] && j-i+1 > len){
                    len = j - i + 1;
                    start = i;
                }
            }
        }
        
        return s.substr(start, len);
    }
};