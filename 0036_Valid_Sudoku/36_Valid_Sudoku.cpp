/**
Runtime: 24 ms, faster than 57.71% of C++ online submissions for Valid Sudoku.
Memory Usage: 19.9 MB, less than 37.46% of C++ online submissions for Valid Sudoku.
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //row repetition
        vector<vector<int>> row(10, vector<int>(10, 0));
        //column repetition
        vector<vector<int>> col(10, vector<int>(10, 0));
        //3*3 box repetition
        vector<vector<int>> box(10, vector<int>(10, 0));
        
        int v, b;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                v = board[i][j] - '0';
                b = i/3 * 3 + j / 3;
                if(v > 0 && v <= 9){
                    row[i][v] += 1;
                    col[v][j] += 1;
                    box[b][v] += 1;
                    if(row[i][v] > 1 || col[v][j] > 1 || box[b][v] > 1)
                        return false;
                }
            }
        }
        
        return true;
    }
};

/**
Runtime: 24 ms, faster than 55.52% of C++ online submissions for Valid Sudoku.
Memory Usage: 20.6 MB, less than 16.40% of C++ online submissions for Valid Sudoku.
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<string, int> mp;
        int m = board.size();
        int n = board[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j <n; j++){
                if(board[i][j] != '.'){
                    string r = "row" + to_string(i) + board[i][j];
                    string c = "col" + to_string(j) + board[i][j];
                    string b = "box" + to_string(i/3) + to_string(j/3) + board[i][j];
                    if(mp.count(r) || mp.count(c) || mp.count(b))
                        return false;
                    else{
                        mp[r]++;
                        mp[c]++;
                        mp[b]++;
                    }
                }
            }
        }
        return true;
    }
};
