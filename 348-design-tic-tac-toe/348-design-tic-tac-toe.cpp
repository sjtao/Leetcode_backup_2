class TicTacToe {
public:
    vector<vector<int>> board;
    int n;
    TicTacToe(int n) {
        board.assign(n, vector<int>(n, 0));
        this->n = n;
    }
    
    int move(int row, int col, int player) {
        board[row][col] = player;
        int h = 1, v = 1, d = 1, rd = 1;
        for(int i = 0; i < n; ++i){
            if(board[row][i] != player){
                h = 0;
                break;
            }
        }
        for(int i = 0; i < n; ++i){
            if(board[i][col] != player){
                v = 0;
                break;
            }
        }
        for(int i = 0; i < n; ++i){
            if(board[i][i] != player){
                d = 0;
                break;
            }
        }
        for(int i = 0; i < n; ++i){
            if(board[i][n-1-i] != player){
                rd = 0;
                break;
            }
        }
        if(h + v + d + rd == 0)
            return 0;
        
        return player;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */