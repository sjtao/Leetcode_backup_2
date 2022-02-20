class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int best = INT_MIN;
        int cur = 0;
        for(int i = 1; i < prices.size(); i++){
            cur = max(cur, cur+prices[i]-prices[i-1]);
            best = max(best, cur);
        }
        return best == INT_MIN ? 0 : best;
    }
};