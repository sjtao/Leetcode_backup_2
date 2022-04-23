class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        pair<int,int> dirs[8] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int sum = 0;
                for(int k = 0; k < 8; k++){
                    int x = i + dirs[k].first;
                    int y = j + dirs[k].second;
                    if(x < 0 || y < 0 || x >= m || y >= n)
                        continue;
                    if(abs(board[x][y]) == 1)
                        sum ++;
                }
                if(board[i][j] == 1){
                    if(sum < 2 || sum > 3) board[i][j] = -1; //dead
                }
                else if(board[i][j] == 0){
                    if(sum == 3) board[i][j] = 2; //live
                }
            }
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == -1) board[i][j] = 0;
                else if(board[i][j] == 2) board[i][j] = 1;
            }
        }
        
        return;
    }
};