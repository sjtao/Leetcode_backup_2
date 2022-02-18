class Solution {
public:
    pair<int,int> dirs[4] = {{1,0},{0,1},{-1,0},{0,-1}};
    int m, n;
    void dfs(int x, int y, vector<vector<char>>& grid){
        if(grid[x][y] == '0')
            return;
        
        grid[x][y] = '0';
        
        for(int i = 0; i < 4; ++i){
            int ix = x + dirs[i].first;
            int iy = y + dirs[i].second;
            if(ix < 0 || ix >= m || iy < 0 || iy >= n || grid[ix][iy] == '0')
                continue;
            
            dfs(ix, iy, grid);
        }
        
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int island = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == '1'){
                    dfs(i, j, grid);
                    island++;
                }
            }
        }
        return island;
    }
};