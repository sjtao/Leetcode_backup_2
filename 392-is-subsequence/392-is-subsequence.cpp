class Solution {
public:
    bool isSubsequence(string s, string t) {
        //DP
        int ns = s.length();
        int nt = t.length();
        if(ns == 0) return true;
        if(nt < ns) return false;
        
        vector<vector<int>> dp(ns+1, vector<int>(nt+1, 0));
        
        for(int i = 1; i < nt+1; i++){
            for(int j = 1; j < ns+1; j++){
                if(s[j-1] == t[i-1])
                    dp[j][i] = dp[j-1][i-1]+1;
                else
                    dp[j][i] = max(dp[j][i-1], dp[j-1][i]);
            }
            if(dp[ns][i] == ns) return true;
        }
        
        return false;
    }
};