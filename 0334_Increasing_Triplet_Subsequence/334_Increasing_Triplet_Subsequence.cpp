/**
Runtime: 110 ms, faster than 8.24% of C++ online submissions for Increasing Triplet Subsequence.
Memory Usage: 61.6 MB, less than 67.77% of C++ online submissions for Increasing Triplet Subsequence.
*/
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int mn1 = INT_MAX, mn2 = INT_MAX;
        //find mn1 < mn2 < nums[i]
        for(int i = 0; i < nums.size();i++){
            if(nums[i] <= mn1){
                mn1 = nums[i];
            }
            else if(nums[i] <= mn2){
                mn2 = nums[i];
            }
            else
                return true;
        }
        return false;
    }
};
