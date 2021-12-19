/**
Runtime: 31 ms, faster than 23.02% of C++ online submissions for Max Area of Island.
Memory Usage: 23.2 MB, less than 66.56% of C++ online submissions for Max Area of Island.
*/
class Solution {
public:
    int area(vector<vector<int>>& grid, int m, int n, int r, int c){
        if(r < 0 || c < 0 || r >= m || c >= n || grid[r][c] != 1)
            return 0;
        grid[r][c] = -1;
        return 1 + area(grid, m, n, r-1, c) + area(grid, m, n, r+1, c) 
            + area(grid, m, n, r, c+1) + area(grid, m, n, r, c-1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int mx = -1;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                mx = max(mx, area(grid, m, n, i, j));
            }
        }
        
        return mx;
    }
};
