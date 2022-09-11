class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        while(l <= r){
            int m = l + (r-l)/2;
            if(nums[m] == target)
                return m;
            else if(nums[m] > target){
                if((target < nums[0] && nums[m] < nums[0]) || (target >= nums[0] && nums[m] >= nums[0]))
                    r = m-1;
                else if(target < nums[0] && nums[m] >= nums[0])
                    l = m+1;
            }
            else{
                if((target < nums[0] && nums[m] < nums[0]) || (target >= nums[0] && nums[m] >= nums[0]))
                    l = m+1;
                else if(target >= nums[0] && nums[m] < nums[0])
                    r = m-1;
            }
        }
        return -1;
    }
};