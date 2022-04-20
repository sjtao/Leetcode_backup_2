class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int row= m-1, col = 0;
        while(row >= 0 && col < n){
            if(matrix[row][col] < target)
                col++;
            else if(matrix[row][col] > target)
                row--;
            else
                return true;
        }
        return false;
    }
};