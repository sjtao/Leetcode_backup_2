class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> fall(n, -1);
        
        for(int i = 0; i < n; i++){
            int row = 0;
            int col = i;
            int ngb;
            while(row < m){
                ngb = col + grid[row][col];
                if(ngb < 0 || ngb >= n || grid[row][col] * grid[row][ngb] == -1)
                    break;
                row++;
                col = ngb; 
            }
            
            if(row == m) fall[i] = col;            
        }
        
        return fall;
    }
};