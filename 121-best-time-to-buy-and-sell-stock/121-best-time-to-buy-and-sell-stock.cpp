class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cur = 0;
        int best = INT_MIN;
        for(int i = 1; i < prices.size(); i++){
            cur = max(cur+prices[i]-prices[i-1], 0);
            best = max(cur, best);
        }
        return best == INT_MIN ? 0 : best;
    }
};