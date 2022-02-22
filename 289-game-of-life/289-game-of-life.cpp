class Solution {
public:
    pair<int, int> dirs[8] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                int count = 0;
                for(int k = 0; k < 8; ++k){
                    int x = i + dirs[k].first;
                    int y = j + dirs[k].second;
                    if(x < 0 || y < 0 || x > m-1 || y > n-1)
                        continue;
                    if(abs(board[x][y]) == 1)
                        count += 1;
                }
                if(board[i][j] == 1){
                    if(count < 2 || count > 3) board[i][j] = -1;
                }
                else if(board[i][j] == 0){
                    if(count == 3) board[i][j] = 2;
                }
            }
        }
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(board[i][j] == -1)
                    board[i][j] = 0;
                if(board[i][j] == 2)
                    board[i][j] = 1;
            }
        }
        
        return;
    }
};