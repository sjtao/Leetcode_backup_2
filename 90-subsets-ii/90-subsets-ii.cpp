class Solution {
public:
    int n;
    void helper(vector<int>& nums, vector<int>& sets, vector<vector<int>>& ans, int s){
        if(s == n) return;
        
        for(int i = s; i < n; i++){
            if(i!=s && nums[i] == nums[s] || i != s && nums[i] == nums[i-1]) continue;
            sets.push_back(nums[i]);
            ans.push_back(sets);
            helper(nums, sets, ans, i+1);
            sets.pop_back();
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> sets;
        ans.push_back(sets);
        helper(nums, sets, ans, 0);
        return ans;
    }
};