class Solution {
public:
    int m,n, s;
    pair<int, int> dir[4] = {{0,1},{0,-1},{1,0},{-1,0}};
    bool helper(vector<vector<char>>& board, string word, int i, int j, int index){
        if(index == s)
            return true;
        
        if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[index])
            return false;
        
        bool find = false;
        board[i][j] = '0'; //use once only
        
        for(int k = 0; k < 4; k++){
            find = helper(board, word, i+dir[k].first, j+dir[k].second, index+1);
            if(find) break;
        }
        
        board[i][j] = word[index];
        return find;  
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        s = word.length();
        m = board.size();
        n = board[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(helper(board, word, i, j, 0))
                    return true;
            }
        }
        
        return false;
    }
};