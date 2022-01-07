class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, true));
        
        for(int i = n-1; i >= 0; i--){
            for(int j = i+1; j < n; j++){
                dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
            }
        }
        
        int len = INT_MIN;
        int idex;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(dp[i][j] && len < j - i + 1){
                    len = j - i + 1;
                    idex = i;
                }
            }
        }
        
        return s.substr(idex, len);
    }
};