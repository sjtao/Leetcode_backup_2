/**
Runtime: 1144 ms, faster than 23.05% of C++ online submissions for Target Sum.
Memory Usage: 9 MB, less than 71.57% of C++ online submissions for Target Sum.
*/

class Solution {
public:
    int SumHelper(vector<int>& nums, int n, int target){
        if(n < 0 && target == 0) return 1;
        if(n < 0) return 0;
        
        return SumHelper(nums, n-1, target+nums[n]) + SumHelper(nums, n-1, target-nums[n]);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        return SumHelper(nums, nums.size()-1, target);
    }
};
