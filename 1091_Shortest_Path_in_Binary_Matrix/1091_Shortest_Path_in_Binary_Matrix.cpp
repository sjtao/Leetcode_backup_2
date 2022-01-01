/***/
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;
        
        pair<int, int> dirs[8] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
        queue<pair<int, int>> qe;
        pair<int, int> d;
        
        qe.push({0,0});
        grid[0][0] = 1;
   
        while(!qe.empty()){
            d = qe.front(); qe.pop();
            int r = d.first, c = d.second;
            int distance = grid[r][c];
            if(r == n-1 && c == n-1)
                return distance;
            
            for(int i = 0; i < 8; i++){
                int nr = r + dirs[i].first;
                int nc = c + dirs[i].second;
                if(nr < 0 || nc < 0 || nr >= n || nc >= n || grid[nr][nc] != 0)
                    continue;
                qe.push({nr,nc});
                grid[nr][nc] = distance + 1;
            }
        }
        
        return -1;
        
    }
};
