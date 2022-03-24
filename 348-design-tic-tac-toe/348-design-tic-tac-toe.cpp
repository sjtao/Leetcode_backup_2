class TicTacToe {
public:
    vector<int> Row;
    vector<int> Col;
    int diag, antidiag;
    int n;
    TicTacToe(int n) {
        Row.assign(n, 0);
        Col.assign(n, 0);
        diag = 0;
        antidiag = 0;
        this->n = n;
    }
    
    int move(int row, int col, int player) {
        int d = player == 1 ? 1 : -1;
        Row[row] += d;
        Col[col] += d;
        if(row == col)
            diag += d;
        if(row + col == n-1)
            antidiag += d;
        
        if(abs(Row[row]) == n || abs(Col[col]) == n || abs(diag) == n || abs(antidiag) == n)
            return player;
        
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */