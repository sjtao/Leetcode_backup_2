class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int fresh = 0;
        int m = grid.size();
        int n = grid[0].size();
        pair<int, int> dirs[4] = {{0,1},{1,0},{0,-1},{-1,0}};
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2)
                    q.push({i,j});
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }
        
        int step = -1;
        while(!q.empty()){
            int s = q.size();
            while(s > 0){
                auto t = q.front();
                q.pop();
                int x = t.first;
                int y = t.second;
                for(int i = 0; i < 4; i++){
                    int ix = x + dirs[i].first;
                    int iy = y + dirs[i].second;
                    if(ix < 0 || iy < 0 || ix >= m || iy >= n || grid[ix][iy] != 1)
                        continue;
                    grid[ix][iy] = 2;
                    q.push({ix, iy});
                    fresh--;
                }
                s--;
            }
            step++;
        }
        //the last iteration: q{n-1,n-1} as (n-1,n-1) is the last rotten orange
        //till this time, q.empty() is false but no fresh oranges could be rotten
        if(step == -1) step = 0;
        if(fresh > 0) step = -1;
        return step;
    }
};