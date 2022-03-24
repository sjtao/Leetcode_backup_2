class Solution {
public:
    
    int minCost(vector<vector<int>>& costs) {  
        int n = costs.size(); //# of houses
        for(int i = n-2; i >= 0; i--){
            costs[i][0] += min(costs[i+1][1], costs[i+1][2]);
            costs[i][1] += min(costs[i+1][0], costs[i+1][2]);
            costs[i][2] += min(costs[i+1][0], costs[i+1][1]);
        }
        return *min_element(costs[0].begin(), costs[0].end());
    }
};