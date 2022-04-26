class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = 0;
        int best = INT_MIN;
        for(int n : nums){
            cur = max(cur + n, n);
            best = max(best, cur);
        }
        return best;
    }
};