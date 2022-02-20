class Solution {
public:
    unordered_map<int,int> mp;
    int helper(vector<int>& nums, int n){
        if(n == 0)
           return nums[0];
        if(n == 1)
            return max(nums[0], nums[1]);
        
        if(mp.find(n) == mp.end()){
            mp[n] = max(helper(nums, n-1), nums[n] + helper(nums,n-2));
        }
        
        return mp[n];
        
    }
    int rob(vector<int>& nums) {
        return helper(nums, nums.size()-1);
    }
};