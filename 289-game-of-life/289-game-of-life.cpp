class Solution {
public:
    pair<int,int> dirs[8] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int sum = 0;
                for(int k = 0; k < 8; k++){
                    int ki = i + dirs[k].first;
                    int kj = j + dirs[k].second;
                    if(ki < 0 || kj < 0 || ki >= m || kj >= n)
                        continue;
                    if(abs(board[ki][kj]) == 1)
                        sum ++;
                }
                if(board[i][j] == 1){
                    if (sum < 2 || sum > 3)
                        board[i][j] = -1;//to dead
                } 
                else{
                    if(sum == 3)
                        board[i][j] = 2;//to live
                }
            }
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == -1)
                    board[i][j] = 0;
                if(board[i][j] == 2)
                    board[i][j] = 1;
            }
        }
        return;
    }
};