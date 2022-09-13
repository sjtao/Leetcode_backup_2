class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(9, false));
        vector<vector<bool>> col(9, vector<bool>(9, false));
        vector<vector<bool>> box(9, vector<bool>(9, false));
        
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int d = board[i][j] - '0';
                    d -= 1;
                    if(row[i][d] || col[j][d] || box[i/3*3+j/3][d])
                        return false;
                    row[i][d] = true;
                    col[j][d] = true;
                    box[i/3*3+j/3][d] = true;
                }
            }
        }
        return true;
    }
};