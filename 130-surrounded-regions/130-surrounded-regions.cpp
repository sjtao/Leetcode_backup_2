class Solution {
public:
    pair<int,int> dirs[4] = {{0,1},{0,-1},{1,0},{-1,0}};
    int m, n;
    
    void bfs(vector<vector<char>>& board, int row, int col){
        queue<pair<int,int>> q;
        q.push({row, col});
        
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            
            int r = p.first;
            int c = p.second;
            if(board[r][c] != 'O')
                continue;
        
            board[r][c] = 'E';
            for(int i = 0; i < 4; ++i){
                int x = r + dirs[i].first;
                int y = c + dirs[i].second;
                if(x < 0 || y < 0 || x >= m || y >= n)
                    continue;
                q.push({x, y});
            }
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
            bfs(board, i, 0);
            bfs(board, i, n-1);
        }
        
        for(int i = 0; i < n; ++i){
            bfs(board, 0, i);
            bfs(board, m-1, i);
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