/**
Runtime: 116 ms, faster than 35.25% of C++ online submissions for Best Time to Buy and Sell Stock with Transaction Fee.
Memory Usage: 55.1 MB, less than 56.94% of C++ online submissions for Best Time to Buy and Sell Stock with Transaction Fee.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int sale = 0;
        int hold = -prices[0];
        for(int i = 1; i < n; i++){
            sale = max(hold + prices[i]-fee, sale);
            hold = max(hold, sale - prices[i]);
        }
        return sale;
    }
};
