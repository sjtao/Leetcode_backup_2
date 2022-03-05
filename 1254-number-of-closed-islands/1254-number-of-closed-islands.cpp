class Solution {
public:
    int m, n;
    
    bool dfs(vector<vector<int>>& grid, int x, int y){
        if(x < 0 || y < 0 || x >= m || y >= n)
            return false;
        
        if(grid[x][y] == 1)
            return true;
        
        grid[x][y] = 1;
        
        bool d1 = dfs(grid, x+1, y);
        bool d2 = dfs(grid, x, y+1);
        bool d3 = dfs(grid, x-1, y);
        bool d4 = dfs(grid, x, y-1);
        return d1 && d2 && d3 && d4;       
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int island = 0;
        m = grid.size();
        n = grid[0].size();
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 0){
                    if(dfs(grid, i, j))
                        island++;
                }
            }
        }
        return island;
    }
};