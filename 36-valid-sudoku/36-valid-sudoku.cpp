class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        if(n != 9) return false;
        unordered_set<char> st;
        //row
        for(int i = 0; i < 9; ++i){
            st.clear();
            for(int j = 0; j < 9; ++j){
                if(board[i][j] != '.'){
                    if(st.count(board[i][j]))
                        return false;
                    st.insert(board[i][j]);
                }
            }
        }
        
        //col
        for(int i = 0; i < 9; ++i){
            st.clear();
            for(int j = 0; j < 9; ++j){
                if(board[j][i] != '.'){
                    if(st.count(board[j][i]))
                        return false;
                    st.insert(board[j][i]);
                }
            }
        }
        
        //3*3 box
        for(int i = 0; i < 9; i += 3){
            for(int j = 0; j < 9; j+=3){
                st.clear();
                for(int r = i; r < i+3; ++r){
                    for(int l = j; l < j+3; ++l){
                        if(board[r][l] != '.'){
                            if(st.count(board[r][l]))
                                return false;
                            st.insert(board[r][l]);
                        }
                    }
                }
            }
        }
        
        return true;
    }
};