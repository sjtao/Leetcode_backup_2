class Solution {
public:
    unordered_map<int,int> mp;
    int helper(vector<int>& cost, int n){
        if(n <= 1)
            return 0;
        
        if(mp.find(n) == mp.end())
            mp[n] = min(helper(cost, n-1) + cost[n-1], helper(cost, n-2) + cost[n-2]);
        
        return mp[n];
        
    }
    int minCostClimbingStairs(vector<int>& cost) {
        return helper(cost, cost.size());
    }
};