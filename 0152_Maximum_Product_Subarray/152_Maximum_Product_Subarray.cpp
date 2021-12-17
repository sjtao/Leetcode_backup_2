/**
Runtime: 8 ms, faster than 37.16% of C++ online submissions for Maximum Product Subarray.
Memory Usage: 13.8 MB, less than 5.82% of C++ online submissions for Maximum Product Subarray.
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        int min_cur = nums[0];
        int max_cur = nums[0];
        int best = max_cur;
        int mi, mx;
        //Kadane's algorithm 
        for(int i = 1; i < n; i++){
            mi = min_cur;
            mx = max_cur;
            min_cur = min(min(mi * nums[i], mx * nums[i]), nums[i]);
            max_cur = max(max(mi * nums[i], mx * nums[i]), nums[i]);
            best = max(max_cur, best);
        }
        
        return best;
    }
};
