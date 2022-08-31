class Solution {
public:
    pair<int,int> dirs[4] = {{0,1},{0,-1},{1,0},{-1,0}};
    
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2)
                    q.push({i,j});
                if(grid[i][j] == 1)
                    fresh++;
            }
        }
        if(fresh == 0) return 0;
        
        int k = -1;
        while(!q.empty()){
            int s = q.size();
            for(int j = 0; j < s; j++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i = 0; i < 4; i++){
                    int ix = x + dirs[i].first;
                    int iy = y + dirs[i].second;
                    if(ix < 0 || iy < 0 || ix >= m || iy >= n || grid[ix][iy] != 1)
                        continue;
                    grid[ix][iy] = 2;
                    fresh--;
                    q.push({ix, iy});
                }
            }
            k++;
        }
        return fresh == 0 ? k : -1;
    }
};