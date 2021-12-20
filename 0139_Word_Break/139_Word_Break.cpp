/**
Runtime: 12 ms, faster than 57.98% of C++ online submissions for Word Break.
Memory Usage: 13.1 MB, less than 50.90% of C++ online submissions for Word Break.
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> word_set(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        for(int i = 1; i <= s.length(); i++){
            for(int j = 0; j < i; j++){
                if(dp[j] && word_set.find(s.substr(j, i-j)) != word_set.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
};
