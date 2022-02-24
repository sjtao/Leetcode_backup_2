class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;
        if(nums[0] == 0) return false;
        int i = 0, mx = nums[0];
        for(; i <= mx && mx < n-1; ++i){
            mx = max(i+nums[i], mx);
        }
        return mx >= n-1;
        
    }
};