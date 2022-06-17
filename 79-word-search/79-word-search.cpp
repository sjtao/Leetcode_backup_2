class Solution {
public:
    int m, n, l;
    pair<int,int> dirs[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    
    bool dfs(vector<vector<char>>& board, vector<vector<int>>& visited, string word, int s, int e, int k){
        if(k == l)
            return true;
        bool ans = false;
        for(int i = 0; i < 4; i++){
            int x = s + dirs[i].first;
            int y = e + dirs[i].second;
            if(x < 0 || y < 0 || x >= m || y >= n || board[x][y] != word[k] || visited[x][y] == 1)
                continue;
            visited[x][y] = 1;
            ans = dfs(board, visited, word, x, y, k+1);
            if(ans) break;
        }
        visited[s][e] = 0;
        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        l = word.length();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0]){
                    visited[i][j] = 1;
                    if(dfs(board, visited, word, i, j, 1))
                        return true;
                }
            }
        }

        return false;
    }
};