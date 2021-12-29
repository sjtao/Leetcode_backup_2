/**
Runtime: 372 ms, faster than 81.81% of C++ online submissions for Range Sum Query 2D - Immutable.
Memory Usage: 148.1 MB, less than 43.86% of C++ online submissions for Range Sum Query 2D - Immutable.
*/

class NumMatrix {
public:
    vector<vector<int>> sum; 
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();   
        sum = vector<vector<int>>(m, vector<int>(n)); //(0,0, i,j)
        sum[0][0] = matrix[0][0];
        
        for(int i = 1; i < m; i++)
            sum[i][0] = sum[i-1][0] + matrix[i][0];
        
        for(int i = 1; i < n; i++)
            sum[0][i] = sum[0][i-1] + matrix[0][i];
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = sum[row2][col2];
        int los = 0;
        los += (row1-1 >= 0 && col1-1>=0) ? sum[row1-1][col1-1] : 0;
        los -= (row1-1 >= 0) ? sum[row1-1][col2] : 0;
        los -= (col1-1 >= 0) ? sum[row2][col1-1] : 0;
            
        return  ans + los;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
