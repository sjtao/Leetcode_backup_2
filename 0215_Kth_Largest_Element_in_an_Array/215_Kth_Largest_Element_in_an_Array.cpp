/**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Kth Largest Element in an Array.
Memory Usage: 10 MB, less than 56.81% of C++ online submissions for Kth Largest Element in an Array.
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n-k];
    }
};
