/**
Runtime: 1010 ms, faster than 5.62% of C++ online submissions for Longest Palindromic Substring.
Memory Usage: 30.1 MB, less than 37.31% of C++ online submissions for Longest Palindromic Substring.
*/
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
        
        int mx = INT_MIN, ix;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(dp[i][j] && mx < (j-i+1)){
                    mx = j-i+1;
                    ix = i;
                }
                    
            }
        }
        
        return s.substr(ix, mx);
    }
};
