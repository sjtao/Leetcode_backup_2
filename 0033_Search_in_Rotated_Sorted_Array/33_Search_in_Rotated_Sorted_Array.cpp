/**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Search in Rotated Sorted Array.
Memory Usage: 11 MB, less than 74.44% of C++ online submissions for Search in Rotated Sorted Array.
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n-1, mid;
        while(left <= right){
            mid = left + (right - left) / 2;
            if(nums[mid] == target) return mid;
            if(nums[mid] >= nums[left]){
                if(target >= nums[left] && target < nums[mid])
                    right = mid - 1;              
                else
                    left = mid + 1;           
            }
            else{
                if(target <= nums[right] && target > nums[mid])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};
