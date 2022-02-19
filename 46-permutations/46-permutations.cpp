class Solution {
public:
    int n;
    void helper(vector<int>& nums, vector<vector<int>>& ans, int d){
        if(d == n){
            ans.push_back(nums);
            return;
        }
        
        for(int i = d; i < n; i++){
            swap(nums[i], nums[d]);
            helper(nums, ans, d+1);
            swap(nums[i], nums[d]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> t;
        vector<vector<int>> ans;
        n = nums.size();
        helper(nums, ans, 0);
        return ans;
        
    }
};