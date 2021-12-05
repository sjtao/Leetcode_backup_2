/**
Runtime: 28 ms, faster than 72.10% of C++ online submissions for Rotate Array.
Memory Usage: 26.4 MB, less than 5.56% of C++ online submissions for Rotate Array.
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if (k == 0) return;
        
        vector<int> ans;
        for(int i = n-k; i < n; i++){
            ans.push_back(nums[i]);
        }
        for(int i = 0; i < n-k; i++){
            ans.push_back(nums[i]);
        }
        nums = ans;
        
        return;
    }
};
