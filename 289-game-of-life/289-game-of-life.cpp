class Solution {
public:
    pair<int, int> dirs[8] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> cb(m, vector<int>(n));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                int count = 0;
                for(int k = 0; k < 8; ++k){
                    int x = i + dirs[k].first;
                    int y = j + dirs[k].second;
                    if(x < 0 || y < 0 || x > m-1 || y > n-1)
                        continue;
                    count += board[x][y];
                }
                if(board[i][j]){
                    if(count < 2 || count > 3) cb[i][j] = 0;
                    else cb[i][j] = 1;
                }
                else{
                    if(count == 3) cb[i][j] = 1;
                    else cb[i][j] = 0;
                }
            }
        }
        
        board = cb;
        return;
    }
};