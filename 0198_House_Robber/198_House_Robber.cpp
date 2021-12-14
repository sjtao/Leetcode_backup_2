/**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for House Robber.
Memory Usage: 7.8 MB, less than 20.81% of C++ online submissions for House Robber.
*/

class Solution {
private:
    unordered_map<int,int> mp;
public:
    int robHelper(vector<int>& nums, int n){
        if(n == 0) return nums[0];
        if(n == 1) return max(nums[0], nums[1]);
        
        if(mp.find(n) == mp.end())
            mp[n] = max(robHelper(nums, n-1), robHelper(nums, n-2) + nums[n]);
        
        return mp[n];
        
    }
    
    int rob(vector<int>& nums) {
        return robHelper(nums, nums.size()-1);
    }
};
