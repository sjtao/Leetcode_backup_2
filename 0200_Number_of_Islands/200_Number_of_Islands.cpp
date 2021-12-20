/**
Runtime: 36 ms, faster than 56.32% of C++ online submissions for Number of Islands.
Memory Usage: 12.3 MB, less than 58.70% of C++ online submissions for Number of Islands.
*/
//DFS
class Solution {
private:
    pair<int, int> dirs[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m, n;
public:
    void DFS(vector<vector<char>>& grid, int x, int y){
        if(x < 0 || y < 0 || x >= m || y >= n)
            return;
        
        if(grid[x][y] == '0')
            return;
        
        grid[x][y] = '0';
        
        for(int i = 0; i < 4; i++){
            DFS(grid, x + dirs[i].first, y + dirs[i].second);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int island = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    island ++;
                    DFS(grid, i, j);
                }    
            }
        }
        return island;
    }
};
