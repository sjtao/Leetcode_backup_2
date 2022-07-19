class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> trig;
        
        for(int i = 1; i <= numRows; i++){
            vector<int> temp(i, 1);
            trig.push_back(temp);
        }
        
        for(int i = 2; i < numRows; i++){
            for(int j = 1; j < i; j++){
                trig[i][j] = trig[i-1][j-1] + trig[i-1][j];
            }
        }
        
        return trig;
    }
};