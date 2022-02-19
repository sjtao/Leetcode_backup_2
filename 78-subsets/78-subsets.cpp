class Solution {
public:
    int n;
    void helper(vector<int>& nums, vector<vector<int>>& ans, vector<int>& t, int d){
        if(d == n){
            return;
        }
        
        for(int i = d; i < n; i++){
            t.push_back(nums[i]);
            ans.push_back(t);
            helper(nums, ans, t, i+1);
            t.pop_back();
        }
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> t;
        n = nums.size();
        ans.push_back(t);
        helper(nums, ans, t, 0);
        return ans;
    }
};