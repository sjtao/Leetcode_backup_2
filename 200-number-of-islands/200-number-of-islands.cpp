class Solution {
public:
    pair<int,int> dirs[4] = {{1,0},{0,1},{-1,0},{0,-1}};
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        int island = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == '1'){
                    island++;
                    q.push({i,j});
                    while(!q.empty()){
                        auto t = q.front();
                        q.pop();
                        for(int k = 0; k < 4; ++k){
                            int kx = t.first + dirs[k].first;
                            int ky = t.second + dirs[k].second;
                            if(kx < 0 || kx >= m || ky < 0 || ky >= n || grid[kx][ky] == '0')
                                continue;
                            grid[kx][ky] = '0';
                            q.push({kx, ky});
                        }
                    }
                }
            }
        }
        return island;
    }
};