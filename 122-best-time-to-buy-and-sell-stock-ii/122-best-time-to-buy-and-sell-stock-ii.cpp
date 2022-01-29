class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cur = 0;
        int best = INT_MIN;
        for(int i = 1; i < prices.size(); i++){
            //compare buy and sell on the different/same day
            cur = max(cur + prices[i] - prices[i-1], cur); 
            best = max(best, cur);
        }
        return best == INT_MIN ? 0 : best;
    }
};