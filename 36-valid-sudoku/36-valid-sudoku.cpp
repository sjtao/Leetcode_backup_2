class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        if(n != 9) return false;
        bool row[9][9] = {false};
        bool col[9][9] = {false};
        bool box[9][9] = {false};

        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(board[i][j] != '.'){
                    int x = board[i][j] - '0';
                    x -= 1; //sudoku values: 1 - 9 --> index 0-8
                    if(row[i][x] || col[j][x] || box[i/3*3+j/3][x])//already existed
                        return false;
                    row[i][x] = true;
                    col[j][x] = true;
                    box[i/3*3+j/3][x] = true;
                }
            }
        }

        return true;
    }
};