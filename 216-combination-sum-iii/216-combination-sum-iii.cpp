class Solution {
public:
    vector<vector<int>> ans;
    int K;
    void backtrack(int start, int remind, vector<int>& comb){
        if(remind == 0 && comb.size() == K){
            ans.push_back(comb);
            return;
        }
        else if(remind < 0 || comb.size() == K)
            return;
        
        for(int i = start; i <= 9; i++){
            comb.push_back(i);
            backtrack(i+1, remind-i, comb);
            comb.pop_back();
        }
        
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if(k >= n) return ans;
        K = k;
        
        vector<int> comb;
        backtrack(1, n, comb);
        
        return ans;
        
        
    }
};