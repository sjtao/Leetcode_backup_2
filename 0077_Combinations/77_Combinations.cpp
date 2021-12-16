/**
Runtime: 549 ms, faster than 8.60% of C++ online submissions for Combinations.
Memory Usage: 164.1 MB, less than 16.97% of C++ online submissions for Combinations.
*/

class Solution {
public:
    void combineHelper(int s, int n, int k, vector<int> cbm, vector<vector<int>> &ans){
        if(cbm.size() == k){
            ans.push_back(cbm);
            return;
        }
        
        for(int i = s; i <= n; i++){
            cbm.push_back(i);
            combineHelper(i+1, n, k, cbm, ans);
            cbm.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
      //backtracking
        vector<vector<int>> ans;
        vector<int> cbm;
        combineHelper(1, n, k, cbm, ans);
        return ans;
    }
};
