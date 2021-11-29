/**
Runtime: 20 ms, faster than 81.81% of C++ online submissions for Move Zeroes.
Memory Usage: 19.3 MB, less than 56.26% of C++ online submissions for Move Zeroes.
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int j = 0;
        for(int i = 0; i < len; i++){
            if(nums[i] != 0){
                nums[j] = nums[i];
                j++;
            }
        }
        while(j < len){
            nums[j] = 0;
            j++;
        }
        
    }
};
