/**
Runtime: 20 ms, faster than 62.20% of C++ online submissions for Longest Common Subsequence.
Memory Usage: 13.1 MB, less than 14.86% of C++ online submissions for Longest Common Subsequence.
*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector< vector<int> > dp(text1.size()+1, vector<int>(text2.size()+1));
        
        for (int i = 1; i <= text1.size(); i++)
            for (int j = 1; j <= text2.size(); j++)
                dp[i][j] = (text1[i-1] == text2[j-1]) ? dp[i-1][j-1]+1 : max(dp[i-1][j], dp[i][j-1]);
        
        return dp[text1.size()][text2.size()];
    }
};
