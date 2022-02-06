class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        //bfs
        int n = grid.size();
        
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0)
            return -1;
        
        queue<pair<int,int>> q;
        q.push({0,0});
        
        pair<int, int> dirs[8] = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
        grid[0][0] = 1;
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            
            if(t.first == n-1 && t.second == n-1)
                return grid[n-1][n-1];
            
            for(int i = 0; i < 8; i++){
                int x = t.first + dirs[i].first;
                int y = t.second + dirs[i].second;
                if(x < 0 || y < 0 || x > n-1 || y > n-1 || grid[x][y] != 0)
                    continue;
                q.push({x, y});
                grid[x][y] = grid[t.first][t.second] + 1;
            }
        }
        
        return -1;
    }
};