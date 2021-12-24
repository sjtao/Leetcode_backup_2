/**
Runtime: 8 ms, faster than 77.98% of C++ online submissions for Paint House.
Memory Usage: 9.5 MB, less than 97.02% of C++ online submissions for Paint House.
*/

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        //costs[i][0]: red, cost[i][1]: blue, cost[i][2]: green
        int n = costs.size();
        
        for(int i = 1; i < n; i++){
            costs[i][0] += min(costs[i-1][1], costs[i-1][2]);
            costs[i][1] += min(costs[i-1][0], costs[i-1][2]);
            costs[i][2] += min(costs[i-1][0], costs[i-1][1]);
        }
        
        return min(costs[n-1][0],min(costs[n-1][1], costs[n-1][2]));
        
    }
};
