/**
Runtime: 8 ms, faster than 45.05% of C++ online submissions for Best Time to Buy and Sell Stock II.
Memory Usage: 13.1 MB, less than 8.92% of C++ online submissions for Best Time to Buy and Sell Stock II.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cur = 0;
        int best = INT_MIN;
        for(int i = 0; i < n-1; i++){
            cur = max(cur - prices[i] + prices[i+1], cur);
            best = max(best, cur);
        }
        return best == INT_MIN ? 0 : best;
    }
};
