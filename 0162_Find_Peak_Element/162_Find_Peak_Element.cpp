/**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Find Peak Element.
Memory Usage: 8.8 MB, less than 48.67% of C++ online submissions for Find Peak Element.
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1, mid;
        while(low < high){
            mid = low + (high - low) / 2;
            if(nums[mid] > nums[mid+1]){
                high = mid;
            }
            else
                low = mid+1;
        }
        return low;
    }
};
