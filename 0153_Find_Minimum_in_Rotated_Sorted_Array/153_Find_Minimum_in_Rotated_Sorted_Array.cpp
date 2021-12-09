/**
Runtime: 4 ms, faster than 60.37% of C++ online submissions for Find Minimum in Rotated Sorted Array.
Memory Usage: 10.3 MB, less than 22.56% of C++ online submissions for Find Minimum in Rotated Sorted Array.
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1, mid;
        if (nums[high] >= nums[0]) {
            return nums[0];
        }
        while(low < high){
            mid = low + (high - low) / 2;
            if(nums[mid] > nums[mid+1])
                return nums[mid+1];
            if(nums[mid] < nums[mid-1])
                return nums[mid];
            if(nums[mid] > nums[0])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};
