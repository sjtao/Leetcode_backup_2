class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int row = words.size();
        int col = 0;
        for(int i = 0; i < row; ++i)
            col = col > words[i].length() ? col : words[i].length();
        
        int m = max(row, col);
        if(row != col) return false;
        
        for(int k = 0; k < m; ++k){
            string a = words[k], b = "";
            for(int i = 0; i < row && k < words[i].length(); ++i)
                b += words[i][k];
            if(a != b)
                return false;
        }
        return true;
    }
};