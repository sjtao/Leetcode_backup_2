class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9] = {0};
        int col[9] = {0};
        int box[9] = {0};
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(board[i][j] == '.')
                    continue;
                int m = board[i][j] - '0';
                int pos = 1 << (m-1);
                if(row[i] & pos || col[j] & pos || box[i/3*3+j/3] & pos)
                    return false;
                
                row[i] |= pos;
                col[j] |= pos;
                box[i/3*3+j/3] |= pos;
            }
        }
        return true;
    }
};