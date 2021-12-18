/**
Runtime: 4 ms, faster than 71.19% of C++ online submissions for Permutations.
Memory Usage: 7.5 MB, less than 91.52% of C++ online submissions for Permutations.
*/

class Solution {
public:
    void helper(vector<vector<int>>& ans, vector<int>& nums, int s, int e){        
         if(s == e-1){
             ans.push_back(nums);
             return;
         }

        for(int i = s; i < e; i++){
            swap(nums[s], nums[i]);
            helper(ans, nums, s+1, e);
            swap(nums[s], nums[i]);
        }

        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(ans, nums, 0, nums.size());
        return ans;
    }
};
