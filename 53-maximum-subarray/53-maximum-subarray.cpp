class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = 0, best = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            cur = max(nums[i], cur+nums[i]);
            best = max(cur, best);
        }
        return best;
    }
};