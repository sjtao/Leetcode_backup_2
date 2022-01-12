class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int sold = 0;
        int hold = -prices[0];
        for(int i = 1; i < n; i++){
            sold = max(hold + prices[i]-fee, sold);
            hold = max(sold - prices[i], hold);
        }
        return sold;
    }
};