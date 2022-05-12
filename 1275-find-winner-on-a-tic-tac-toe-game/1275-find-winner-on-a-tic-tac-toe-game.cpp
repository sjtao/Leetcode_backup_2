class Solution {
public:
   
    string tictactoe(vector<vector<int>>& moves) {
        vector<int> row(3, 0), col(3, 0);
        int diag = 0, antidiag = 0;
        int player = 1;
        
        for(vector<int> m : moves){
            int r = m[0];
            int c = m[1];
            
            row[r] += player;
            col[c] += player;
            if(r == c) diag += player;
            if(r + c == 2) antidiag += player;
            
            if(abs(row[r]) == 3 || abs(col[c]) == 3 || \
              abs(diag) == 3 || abs(antidiag) == 3)
                return player == 1 ? "A" : "B";
            
            player *= -1;
        }
        
        return moves.size() == 9 ? "Draw" : "Pending";
        
        
    }
};