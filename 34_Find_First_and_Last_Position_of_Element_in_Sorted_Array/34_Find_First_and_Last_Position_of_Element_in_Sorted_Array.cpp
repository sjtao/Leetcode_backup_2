/**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
Memory Usage: 13.7 MB, less than 62.82% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
*/

class Solution {
public:
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ps(2,-1);
        
        int n = nums.size();
        int low = 0, high = n-1, mid;
 
        while(low <= high){
            mid = low + (high - low) / 2;
            if(nums[mid] == target){
                if(mid == low || nums[mid] != nums[mid-1]){
                    ps[0] = mid;
                    break;
                }
                else{
                    ps[0] = mid - 1;
                    high = mid-1;
                }
            }
            else if(nums[mid] < target)
                low = mid+1;
            else
                high = mid-1;
        }
        
        low = 0;
        high = n-1;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(nums[mid] == target){
                if(mid == high || nums[mid] != nums[mid+1]){
                    ps[1] = mid;
                    break;
                }
                else{
                    ps[1] = mid + 1;
                    low = mid + 1;
                }
            }
            else if(nums[mid] < target)
                low = mid+1;
            else
                high = mid-1;
        }
        
        return ps;
    }
};
