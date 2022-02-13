class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cur = 0;
        int best = 0;
        for(int i = 1; i < prices.size(); i++){
            cur = max(0, cur + prices[i]-prices[i-1]);
            best = max(cur, best);
        }
        return best;
    }
};