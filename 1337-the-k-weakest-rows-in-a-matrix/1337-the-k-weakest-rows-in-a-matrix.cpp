class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n =mat[0].size();
        vector<int> ans;
        vector<bool> row(m, 0);
        bool findK = 0;
        for(int j = 0; j < n; j++){
            for(int i = 0; i < m; i++){
                if(row[i] == 1)
                    continue;
                if(mat[i][j] == 0){
                    ans.push_back(i);
                    row[i] = 1;
                }
                if(ans.size() == k){
                    findK = 1;
                    break;
                }
            }
            if(findK)
                break;
        }
        
        for(int i = 0; i < m; i++){
            if(ans.size() < k && row[i] == 0)
                ans.push_back(i);
        }
        
        return ans;
    }
};