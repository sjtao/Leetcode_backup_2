class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = 0;
        int best = INT_MIN;
        for(int n:nums){
            cur = max(n, n+cur);
            best = max(best, cur);
        }
        return best == INT_MIN ? 0 : best;
    }
};