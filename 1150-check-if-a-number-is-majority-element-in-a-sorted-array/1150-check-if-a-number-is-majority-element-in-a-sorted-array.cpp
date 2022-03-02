class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int m;
        while(l <= r){
            m = l + ( r - l) / 2;
            if(nums[m] > target)
                r = m-1;
            else if(nums[m] < target)
                l = m+1;
            else{
                if(m + n/2 < n && nums[m+n/2] == target)
                    return true;
                r = m-1;
            }
        }
        return false;
    }
};