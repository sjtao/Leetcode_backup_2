class Solution {
public:
    int m, n;
    int cnt;
    pair<int,int> dirs[4] = {{0,1}, {0,-1},{1,0},{-1,0}};
    
    void dfs(vector<vector<int>>& grid, int x, int y){
        if(x < 0 || y < 0 || x >= m || y >= n)
            return;
        
        if(grid[x][y] != 1)
            return;
        
        grid[x][y] = cnt;
        for(int k = 0; k < 4; ++k){
            int kx = x + dirs[k].first;
            int ky = y + dirs[k].second;
            dfs(grid, kx, ky);
        }
        
        return;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        //dfs
        m = grid.size();
        n = grid[0].size();
        cnt = 2;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1){
                    dfs(grid, i, j);
                    cnt++;
                }
            }
        }
        
        vector<int> rep(cnt, 0);
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                rep[grid[i][j]]++;
            }
        }
        
        int ans = -1;
        for(int c = 2; c < cnt; ++c)
            ans = max(rep[c], ans);
        
        return ans == -1 ? 0 : ans;
        
    }
};