class Solution {
public:
    pair<int,int> dirs[4] = {{0,1},{0,-1},{1,0},{-1,0}};
    int m, n;
    void dfs(vector<vector<char>>& board, int row, int col){
        if(board[row][col] != 'O')
            return;
        
        board[row][col] = 'E';
        for(int i = 0; i < 4; ++i){
            int x = row + dirs[i].first;
            int y = col + dirs[i].second;
            if(x < 0 || y < 0 || x >= m || y >= n)
                continue;
            dfs(board, x, y);
        }
        return;
    }
    void solve(vector<vector<char>>& board) {
        //dfs
        m = board.size();
        n = board[0].size();
        if(m*n == 0)
            return;
        
        for(int i = 0; i < m; ++i){
            dfs(board, i, 0);
            dfs(board, i, n-1);
        }
        
        for(int i = 0; i < n; ++i){
            dfs(board, 0, i);
            dfs(board, m-1, i);
        }
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                if(board[i][j] == 'E')
                    board[i][j] = 'O';
            }
        }
        
        return;
    }
};