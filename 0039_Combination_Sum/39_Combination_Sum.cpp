/**
Runtime: 4 ms, faster than 93.38% of C++ online submissions for Combination Sum.
Memory Usage: 10.7 MB, less than 96.98% of C++ online submissions for Combination Sum.
*/
class Solution {
public:
    int n;
    void sum(vector<int>& candidates, vector<vector<int>>&group, vector<int>& num, int s, int target){
        if(target < 0) return;
        if(target == 0){
            group.push_back(num);
            return;
        }
        for(int i = s; i < n; i++){
            num.push_back(candidates[i]);
            sum(candidates, group, num, i, target-candidates[i]);
            num.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        vector<vector<int>> group;
        vector<int> num;
        sum(candidates, group, num, 0, target);
        return group;
    }
};
