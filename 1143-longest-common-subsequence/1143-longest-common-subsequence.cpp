class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        if(n1 == 0 || n2 == 0) return 0;
        
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        for(int i = 0; i < n1; i++){
            for(int j = 0; j < n2; j++){
                dp[i+1][j+1] = text1[i] == text2[j] ? dp[i][j]+1 : max(dp[i+1][j], dp[i][j+1]);
            }
        }
        
        return dp[n1][n2];
    }
};