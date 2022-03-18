class Solution {
public:
    bool isPalindrome(string s, int low, int high){
        while(low < high){
            if(s[low++] != s[high--])
                return false;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector(n, false));
        
        for(int i = 0; i < n; i++){
            dp[i][i] = true;
            if (i + 1 < n)
                dp[i][i+1] = (s[i] == s[i+1]);
        }
        
        for(int i = n-3; i >= 0; i--){
            for(int j = i+2; j < n; j++){
                dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
            } 
        }
        
        int a, len = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(dp[i][j]){
                    if(len < j-i+1){
                        len = j-i+1;
                        a = i;
                    }
                }
            }
        }
        return s.substr(a, len);
    }
};