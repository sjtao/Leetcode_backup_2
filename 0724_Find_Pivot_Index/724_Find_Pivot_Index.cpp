/**
Runtime: 20 ms, faster than 85.91% of C++ online submissions for Find Pivot Index.
Memory Usage: 31.1 MB, less than 28.51% of C++ online submissions for Find Pivot Index.
*/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int len = nums.size();
        
        int sum = 0;
        for(int n : nums){
            sum += n;
        }
        int left = 0;
        //sum = 2*left + nums[i]
        for(int i = 0; i < len; i++){
            if(2 * left == sum - nums[i]){
                return i;
            }
            else{
                left += nums[i];
            }
        }
        
        return -1;
    }
};
