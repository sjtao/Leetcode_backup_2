class Solution {
public:
    unordered_map<int,int> map;
    int helper(vector<int>& nums, int n){
        if(n == 0) return nums[0];
        if(n == 1) return max(nums[0], nums[1]);
        
        if(map.find(n) == map.end())
            map[n] = max(nums[n] + helper(nums, n-2), helper(nums, n-1));
        
        return map[n];
    }
    int rob(vector<int>& nums) {
        return helper(nums, nums.size()-1);
    }
};