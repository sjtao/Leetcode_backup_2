class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cur = INT_MAX;
        int best = 0;
        for(int i = 0; i < n; i++){
            cur = min(cur, prices[i]);
            best = max(best, prices[i]-cur);
        }
        return best;
    }
};