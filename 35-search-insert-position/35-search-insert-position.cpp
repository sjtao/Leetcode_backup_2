class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if(nums[0] >= target) return 0;
        if(nums[n-1] < target) return n;
        
        int l = 1, r = n-1;
        while(l <= r){
            int m = l + (r-l)/2;
            if(nums[m] == target)
                return m;
            else if(nums[m] < target)
                l = m + 1;
            else
                r = m - 1;
        }
        
        return l;
    }
};