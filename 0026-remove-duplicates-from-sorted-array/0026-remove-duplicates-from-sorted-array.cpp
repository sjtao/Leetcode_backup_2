class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 1, j = 1;
        for(; i < n; i++){
            if(nums[i] != nums[i-1]){
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};