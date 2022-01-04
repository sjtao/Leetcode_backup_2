/*
Runtime: 12 ms, faster than 79.67% of C++ online submissions for Surrounded Regions.
Memory Usage: 9.7 MB, less than 99.26% of C++ online submissions for Surrounded Regions.
*/

class Solution {
public:
    int m, n;
    void dfs(vector<vector<char>>& board, int i, int j){
        if(i < 0 || j < 0 || i >= m || j >= n|| board[i][j] != 'O') return;
        
        board[i][j] = 'F';
        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
        
        return;
    }
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        
        for(int i = 0; i < m; i++){
            dfs(board, i, 0);
            dfs(board, i, n-1);
        }
        for(int j = 0; j < n; j++){
            dfs(board, 0, j);
            dfs(board, m-1, j);
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == 'F') board[i][j] = 'O';
            }
        }
        
        return;
    }
};
