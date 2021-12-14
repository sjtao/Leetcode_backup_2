/**
Runtime: 108 ms, faster than 87.85% of C++ online submissions for Best Time to Buy and Sell Stock.
Memory Usage: 93.3 MB, less than 52.09% of C++ online submissions for Best Time to Buy and Sell Stock.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //Kadane's Algorithm
        int current = 0;
        int best = INT_MIN;
        for(int i = 1; i < prices.size(); i++){
            current = max(current + prices[i] - prices[i-1], 0);
            best = max(best, current);
        }
        return best == INT_MIN ? 0 : best;
    }
};
