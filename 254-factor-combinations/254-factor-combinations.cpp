class Solution {
public:
    void helper(vector<vector<int>>& results, vector<int>& row, int n){
        int i = row.size() == 0 ? 2 : row.back();
        for(; i <= n/i; ++i){
            if(n%i==0){
                row.push_back(i);
                row.push_back(n/i);
                results.push_back(row);
                row.pop_back();
                helper(results, row, n/i);
                row.pop_back();
            }
        }
    }
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> results;
        vector<int> row;
        helper(results, row, n);
        return results;
    }
};