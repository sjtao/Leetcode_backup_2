//brutal force: time limit exceeded
//Runtime: 208 ms, faster than 6.45% of C++ online submissions for Maximum Subarray.
//Memory Usage: 67.8 MB, less than 7.80% of C++ online submissions for Maximum Subarray.
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        int maxsum = -10000;
        int sumnow = 0;
        for(int i = 0; i < n; i++){
            sumnow += nums[i];
            maxsum = max(maxsum, sumnow);
            sumnow = max(0, sumnow);
        }
        
        return maxsum;
      
    }
};
