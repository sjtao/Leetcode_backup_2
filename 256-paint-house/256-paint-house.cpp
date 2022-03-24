class Solution {
public:
    
    int minCost(vector<vector<int>>& costs) {  
        int n = costs.size(); //# of houses
        vector<int> ct = costs[n-1], ctprev = ct;
        for(int i = n-2; i >= 0; i--){
            ct[0] = costs[i][0] + min(ctprev[1], ctprev[2]);
            ct[1] = costs[i][1] + min(ctprev[0], ctprev[2]);
            ct[2] = costs[i][2] + min(ctprev[0], ctprev[1]);
            ctprev = ct;
        }
        return *min_element(ct.begin(), ct.end());
    }
};