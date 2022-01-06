class Solution {
public:
    int n;
    int length(vector<int>& nums, int elm){
        int et = n-1, st = 0;
        while(st < et){
            if(nums[st] != elm) st++;
            if(nums[et] != elm) et--;
            if(nums[st] == elm && nums[et] == elm) break;
        }
        
        return et-st+1;
    }
    
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> mp;
        n = nums.size();
        
        for(int n : nums)
            mp[n]++;
        
        int degree = -1;
        for(auto t : mp){
            degree = max(degree, t.second);
        }
        
        int ans = n+1;
        for(auto t : mp){
            if(t.second == degree){
                ans = min(ans, length(nums, t.first));
            }
        }
        
        return ans;
        
    }
};