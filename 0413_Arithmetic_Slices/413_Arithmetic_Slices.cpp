
/**
Runtime: 4 ms, faster than 55.55% of C++ online submissions for Arithmetic Slices.
Memory Usage: 7.2 MB, less than 85.33% of C++ online submissions for Arithmetic Slices.
*/

class Solution {
public:
    int sum = 0;
    int slices(vector<int>& nums, int n){
        if(n < 2) return 0;
        int ap = 0;
        if(nums[n] - nums[n-1] == nums[n-1] - nums[n-2]){
            ap = (1 + slices(nums, n-1));
            sum += ap;
        }
        else
            slices(nums, n-1);
        return ap;
        
    }
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        slices(nums, nums.size()-1);
        return sum;        
    }
};
