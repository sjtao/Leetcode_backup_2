class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> ball(n, -1);
        
        for(int i = 0; i < n; i++){
            int row = 0;
            int col = i;
            while(row < m){
                int nextcol = col + grid[row][col];
                if(nextcol < 0 || nextcol >= n || grid[row][col] * grid[row][nextcol] == -1)
                    break;
                row++;
                col = nextcol;
            }
            if(row == m)
                ball[i] = col;
        }
        
        return ball;
    }
};