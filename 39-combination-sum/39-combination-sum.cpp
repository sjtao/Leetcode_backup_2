class Solution {
public:
    vector<vector<int>> res;
    int n;
    void sum(vector<int>& candidates, vector<int>& num, int d, int target){
        if(target == 0){
            res.push_back(num);
            return;
        }
        
        for(int i = d; i < n; i++){
            if(candidates[i] <= target){
                num.push_back(candidates[i]);
                sum(candidates, num, i, target-candidates[i]);
                num.pop_back();
            }
        }
        
        return;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> num;
        n = candidates.size();
        sum(candidates, num, 0, target);
        return res;
    }
};