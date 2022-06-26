class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int best = 0;
        int mn = INT_MAX;
        for(int i = 0; i < n; i++){
            mn = min(mn, prices[i]);
            best = max(best, prices[i] - mn);
        }
        
        return best;
    }
};