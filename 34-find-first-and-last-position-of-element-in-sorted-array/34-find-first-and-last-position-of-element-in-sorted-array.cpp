class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int m;
        
        while(l <= r){
            m = l + (r - l) / 2;
            if(nums[m] >= target)
                r = m-1;
            else
                l = m+1;
            
            if(nums[m] == target)
                ans[0] = m;
        }
        
        l = 0;
        r = n - 1;
        while(l <= r){
            m = l + (r - l) / 2;
            if(nums[m] > target)
                r = m-1;
            else
                l = m+1;
            
            if(nums[m] == target)
                ans[1] = m;
        }
        
        return ans;
    }
};