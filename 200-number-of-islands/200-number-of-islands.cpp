class Solution {
public:
    int m, n;
    pair<int, int> dirs[4] = {{1,0}, {-1,0}, {0,1},{0,-1}};
    void dfshelper(vector<vector<char>>& grid, int sx, int sy){
        if(sx < 0 || sy < 0 || sx >= m || sy >= n || grid[sx][sy] != '1')
            return;
        
        grid[sx][sy] = '2';
        for(int i = 0; i < 4; ++i){
            int ix = sx + dirs[i].first;
            int iy = sy + dirs[i].second;
            dfshelper(grid, ix, iy);
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
                    dfshelper(grid, i, j);
                    island ++;
                }
            }
        }
        return island;
    }
};