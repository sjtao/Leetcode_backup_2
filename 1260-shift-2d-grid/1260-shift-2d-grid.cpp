class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int N = n * m;
        k %= N;
        if(k == 0) return grid;
        
        vector<vector<int>> ans(m, vector<int>(n));
        int cnt = k;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int c = cnt % N;
                int si = c / n;
                int sj = c % n;
                cnt++;
                ans[si][sj] = grid[i][j];
            }
        }
        return ans;
    }
};