class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        for(; j < n; j++){
            if(nums[j] != 0){
                nums[i++] = nums[j];
            }
        }
        
        for(; i < n; i++)
            nums[i] = 0;
        
        return;
    }
};