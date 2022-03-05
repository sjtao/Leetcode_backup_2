class Solution {
public:
    int m, n;
    pair<int,int> dirs[4] = {{0,1}, {0,-1},{1,0},{-1,0}};
    
    int dfs(vector<vector<int>>& grid, int x, int y){
        if(x < 0 || y < 0 || x >= m || y >= n)
            return 0;
        
        if(grid[x][y] != 1)
            return 0;
        
        grid[x][y] = 2;
        
        int num = 1;
        for(int k = 0; k < 4; ++k){
            int kx = x + dirs[k].first;
            int ky = y + dirs[k].second;
            num += dfs(grid, kx, ky);
        }
        
        return num;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        //dfs
        m = grid.size();
        n = grid[0].size();
        int ans = -1;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1){
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }
        
        return ans == -1 ? 0 : ans;
        
    }
};