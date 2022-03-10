class Solution {
public:
    pair<int,int> dirs[4] = {{0,1},{0,-1},{1,0},{-1,0}};
    int m, n;
    
    void dfs(vector<vector<int>>& grid, int x, int y){
        if(x < 0 || y < 0 || x >= m || y >= n || grid[x][y] != 1)
            return;
        
        grid[x][y] = 0;
        for(int k = 0; k < 4; ++k){
            int kx = x + dirs[k].first;
            int ky = y + dirs[k].second;
            dfs(grid, kx, ky);
        }
        
        return;
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();       
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if((i == 0 || i == m-1 || j == 0 || j == n-1) && grid[i][j] == 1)
                    dfs(grid, i, j);
            }
        }
        
        int ans = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1)
                    ans ++;
            }
        }
        return ans;
    }
};