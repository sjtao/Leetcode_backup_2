class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex+1, 1);
        for(int r = 1; r <= rowIndex; r++){
            for(int i = r-1; i > 0; i--){
                row[i] += row[i-1];
            }
        }
        return row;
    }
};