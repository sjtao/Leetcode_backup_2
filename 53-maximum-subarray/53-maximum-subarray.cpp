class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //dp: kadane's
        int cur = 0;
        int best = INT_MIN;
        for(int n : nums){
            cur = max(cur + n, n);
            best = max(cur, best);
        }
        return best;
    }
};