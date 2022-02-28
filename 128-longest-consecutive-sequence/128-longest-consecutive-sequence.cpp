class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n < 2) return n;
        
        int ans = 1;
        int cur = 1;
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i-1] + 1)
                cur ++;
            else if(nums[i] == nums[i-1])
                continue;
            else
                cur = 1;
           ans = max(ans, cur);
        }
        return ans;
    }
};