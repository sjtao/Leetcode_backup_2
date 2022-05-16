class Solution {
public:
    pair<int,int> dirs[8] = {{1,1},{1,-1},{-1,1},{-1,-1},{-1,0},{1,0},{0,-1},{0,1}};
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;
        //bfs
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            if(row == n-1 && col == n-1)
                return grid[row][col];
            
            for(int i = 0; i < 8; i++){
                int x = row + dirs[i].first;
                int y = col + dirs[i].second;
                if(x < 0 || y < 0 || x == n || y == n || grid[x][y] != 0)
                    continue;
                grid[x][y] = grid[row][col]+1;
                q.push({x, y});
            }
        }
        return -1;
    }
};