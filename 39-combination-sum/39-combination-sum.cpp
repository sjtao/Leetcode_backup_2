class Solution {
public:
    int n;
    void helper(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& t, int d, int target){
        if(target == 0){
            ans.push_back(t);
            return;
        }
        if(target < 0)
            return;
        
        for(int i = d; i < n; i++){
            t.push_back(candidates[i]);
            helper(candidates, ans, t, i, target-candidates[i]);
            t.pop_back();
        }
        
        return;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> t;
        n = candidates.size();
        helper(candidates, ans, t, 0, target);
        
        return ans;
    }
};