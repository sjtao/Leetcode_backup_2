class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int,int>> q;
        pair<int,int> dirs[4] = {{-1,0},{1,0},{0,-1},{0,1}};
        
        int fresh = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2)
                    q.push({i,j});
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }
        
        q.push({-1,-1}); //dividor of time step
        int step = -1;
        while(!q.empty()){
            pair<int,int> rt = q.front();
            q.pop();
            int x = rt.first;
            int y = rt.second;
            if(x == -1){
                step++;
                if(!q.empty())
                    q.push({-1,-1});
            }
            else{
                for(int k = 0; k < 4; k++){
                    int kx = x + dirs[k].first;
                    int ky = y + dirs[k].second;
                    if(kx < 0 || ky < 0 || kx >= m || ky >= n || grid[kx][ky] != 1)
                        continue;
                    grid[kx][ky] = 2;
                    q.push({kx,ky});
                    fresh--;
                }
            }
        }
        
        return fresh == 0 ? step : -1;
    }
};