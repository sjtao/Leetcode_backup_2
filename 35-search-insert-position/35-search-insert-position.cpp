class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1, m;
        while(l < r){
            m = l + (r - l) / 2;
            if(nums[m] == target)
                return m;
            else if(nums[m] > target)
                r = m-1;
            else
                l = m+1;
        }
        
        return nums[l] >= target ? l : l+1;
    }
};