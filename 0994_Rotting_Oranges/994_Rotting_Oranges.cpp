/**
Runtime: 4 ms, faster than 90.76% of C++ online submissions for Rotting Oranges.
Memory Usage: 13.1 MB, less than 48.15% of C++ online submissions for Rotting Oranges.
*/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        int fresh=0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]==2)
                    q.push({i,j});
                if(grid[i][j]==1)
                    fresh++;
            }
        }
        
        pair<int, int> dirs[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int step = -1;
        while(!q.empty()){
            int s = q.size();
            int c = 0;
            while(s){
                auto p = q.front(); q.pop(); s--;
                int px = p.first;
                int py = p.second;
                for(int i = 0; i < 4; i++){
                    int x = px + dirs[i].first;
                    int y = py + dirs[i].second;
                    if(x < 0 || y < 0 || x >= m || y >= n || grid[x][y] != 1)
                        continue;
                    grid[x][y] = 2;
                    q.push({x, y});
                    fresh--;
                }
            }
            step++;
        }
        
        if(step == -1) step = 0;
        if(fresh > 0) step = -1; //still have fresh oranges left
        return step;
    }
};
