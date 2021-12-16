/**
Runtime: 32 ms, faster than 74.26% of C++ online submissions for Minimum Difficulty of a Job Schedule.
Memory Usage: 7.5 MB, less than 77.21% of C++ online submissions for Minimum Difficulty of a Job Schedule.
*/
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n < d) return -1;
        
        vector<int> dp(n+1, 1000000);
        dp[n] = 0;
        int mx;
        for(int i = 1; i <= d; i++){
            for(int j = 0; j <= n-i; j++){
                mx = 0; dp[j] = 1000000;
                for(int k = j; k <= n-i; k++){
                    mx = max(mx, jobDifficulty[k]);
                    dp[j] = min(dp[j], mx+dp[k+1]);
                }
            }
        }
        return dp[0];
    }
};
