/**
Runtime: 32 ms, faster than 87.44% of C++ online submissions for Binary Search.
Memory Usage: 27.4 MB, less than 92.65% of C++ online submissions for Binary Search.
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        int pivot;
        while(low <= high){
            pivot = low + (high - low) / 2;
            if(nums[pivot] == target) return pivot;
            if(nums[pivot] > target)
                high = pivot-1;
            else
                low = pivot+1;
        }
        return -1;
    }
};
