class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int best = 0;
        int cur = 0;
        for(int i = 1; i < n; i++){
            cur = max(0, cur+prices[i] - prices[i-1]);
            best = max(cur, best);
        }
        return best;
    }
};