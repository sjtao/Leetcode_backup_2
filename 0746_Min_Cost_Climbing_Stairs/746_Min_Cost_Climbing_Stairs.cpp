/**
Runtime: 8 ms, faster than 51.30% of C++ online submissions for Min Cost Climbing Stairs.
Memory Usage: 13.7 MB, less than 76.43% of C++ online submissions for Min Cost Climbing Stairs.
*/
class Solution {
public:

    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();
        if(n==1) return cost[0];
        if(n==2) return min(cost[0], cost[1]);
        
        //bottom-up
        vector<int> dp(n+1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i < n; i++){
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }
        
        return min(dp[n-1],dp[n-2]);
    }
};
