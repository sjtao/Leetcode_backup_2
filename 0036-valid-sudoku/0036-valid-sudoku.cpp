class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9, vector<int>(9,0));
        vector<vector<int>> col(9, vector<int>(9,0));
        vector<vector<int>> box(9, vector<int>(9,0));
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int x = board[i][j] - '1'; //board number: 1-9
                    int b = (i / 3) * 3 + (j / 3);
                    if(row[i][x] != 0 || col[j][x] != 0 || box[b][x] != 0)
                        return false;
                    row[i][x]++;
                    col[j][x]++;
                    box[b][x]++;
                }
            }
        }
        return true;
    }
};