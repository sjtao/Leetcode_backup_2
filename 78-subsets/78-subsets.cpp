class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>& ans, vector<int>& t, int start){
        if(start == nums.size()){
            return;
        }
        for(int i = start; i < nums.size(); i++){
            t.push_back(nums[i]);
            ans.push_back(t);
            helper(nums, ans, t, i+1);
            t.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> t;
        ans.push_back(t);
        helper(nums, ans, t, 0);
        return ans;
    }
};