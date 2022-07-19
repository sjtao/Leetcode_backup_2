class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> trig;
        
        for(int i = 0; i < numRows; i++){
            vector<int> temp(i+1, 1);
            for(int j = 1; j < i; j++){
                temp[j] = trig[i-1][j-1] + trig[i-1][j];
            }
            trig.push_back(temp);
        }
        
        return trig;
    }
};