/**
Runtime: 13 ms, faster than 26.00% of C++ online submissions for Combination Sum II.
Memory Usage: 10.7 MB, less than 71.13% of C++ online submissions for Combination Sum II.
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
            if(i > s && candidates[i] == candidates[i-1]) continue;
            num.push_back(candidates[i]);
            sum(candidates, group, num, i+1, target-candidates[i]);
            num.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n = candidates.size();
        vector<vector<int>> group;
        vector<int> num;
        sort(candidates.begin(), candidates.end());
        sum(candidates, group, num, 0, target);
        return group;
    }
};
