class Solution {
public:
    pair<int,int> dir[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    int m, n;
    void dfs(vector<vector<char>>& grid, int x, int y){
        grid[x][y] = '0';
        for(int k = 0; k < 4; k ++){
            int kx = x + dir[k].first;
            int ky = y + dir[k].second;
            if(kx < 0 || ky < 0 || kx >= m || ky >= n || grid[kx][ky] != '1')
                continue;
            dfs(grid, kx, ky);
        }
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    cnt += 1;
                    dfs(grid, i, j);
                }    
            }
        }
        return cnt;
    }
};