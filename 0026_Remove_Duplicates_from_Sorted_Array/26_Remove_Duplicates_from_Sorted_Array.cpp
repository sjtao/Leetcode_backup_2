/**
Runtime: 16 ms, faster than 39.21% of C++ online submissions for Remove Duplicates from Sorted Array.
Memory Usage: 18.4 MB, less than 36.72% of C++ online submissions for Remove Duplicates from Sorted Array.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        int dup = nums[0];
        int i = 1;
        for(int j = 1; j < nums.size(); j++){
            if(nums[j] != dup){
                dup = nums[j];
                nums[i] = dup;
                i++;
            }
        }
        return i;
    }
};
