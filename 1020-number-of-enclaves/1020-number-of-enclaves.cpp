class Solution {
public:
    pair<int,int> dirs[4] = {{0,1},{0,-1},{1,0},{-1,0}};
    
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        
        for(int i = 0; i < m; ++i){
            if(grid[i][0] == 1)
                q.push({i,0});
            if(grid[i][n-1] == 1)
                q.push({i,n-1});
        }
        
        for(int i = 1; i < n-1; ++i){
            if(grid[0][i] == 1)
                q.push({0,i});
            if(grid[m-1][i] == 1)
                q.push({m-1,i});
        }
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            if(grid[x][y] == 0)
                continue;
            grid[x][y] = 0;
            for(int k = 0; k < 4; ++k){
                int kx = x + dirs[k].first;
                int ky = y + dirs[k].second;
                if(kx < 0 || ky < 0 || kx >= m || ky >= n || grid[kx][ky] == 0)
                    continue;
                q.push({kx, ky});
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