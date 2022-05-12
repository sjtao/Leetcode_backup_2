class Solution {
public:
    
    vector<vector<int>> board;
    
    bool row(int r, int player){
        for(int i = 0; i < 3; i++){
            if(board[r][i] != player)
                return false;
        }
        return true;
    }
    
     bool col(int c, int player){
        for(int i = 0; i < 3; i++){
            if(board[i][c] != player)
                return false;
        }
        return true;
    }
    
    bool diag(int player){
        for(int i = 0; i < 3; i++){
            if(board[i][i] != player)
                return false;
        }
        return true;
    }
    
    bool antidiag(int player){
        for(int i = 0; i < 3; i++){
            if(board[i][2-i] != player)
                return false;
        }
        return true;
    }
    
    string tictactoe(vector<vector<int>>& moves) {
        board = vector<vector<int>>(3, vector<int>(3, 0));
        int player = 1;
        
        for(vector<int> m : moves){
            int r = m[0];
            int c = m[1];
            board[r][c] = player;
            if(row(r, player) || col(c, player) || \
               (r == c && diag(player)) || (r + c == 2 && antidiag(player))){
                return player == 1 ? "A" : "B";
            }
            
            player *= -1;
        }
        
        return moves.size() == 9 ? "Draw" : "Pending";
        
        
    }
};