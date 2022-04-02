class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int n = nums.size();
        int l = 1, r = n-2, m;
        while(l <= r){
            m = l + (r -l) / 2;
            if(nums[m] > nums[m-1] && nums[m] < nums[m+1])
                l = m+1;
            else if(nums[m] < nums[m-1] && nums[m] > nums[m+1])
                r = m-1;
            else
                return m;
        }
        return -1;
    }
};