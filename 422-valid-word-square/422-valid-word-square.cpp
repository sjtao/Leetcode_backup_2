class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int row = words.size();
        for(int i = 0; i < row; ++i){
            if(row < words[i].size()) return false;
            for(int j = 0; j < words[i].size(); ++j){
                if(words[i][j] != words[j][i])  return false;
            }
        }

        return true;
    }
};