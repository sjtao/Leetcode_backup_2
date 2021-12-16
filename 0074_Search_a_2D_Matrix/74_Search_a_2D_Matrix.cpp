/**
Runtime: 11 ms, faster than 5.49% of C++ online submissions for Search a 2D Matrix.
Memory Usage: 9.3 MB, less than 95.97% of C++ online submissions for Search a 2D Matrix.
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int i, j;
        
        //matrix[i][0]: locate target row position -- i
        for(i = 0; i < row-1; i++){
            if(matrix[i][0] == target || matrix[i+1][0] == target){
                return true;
            }
            if(matrix[i][0] < target && matrix[i+1][0] > target){
                break;
            }
        }
        //matrix[i][j]: locate target col position -- j
        for(j = 0; j < col; j++){
            if(matrix[i][j] == target){
                return true;
            }
        }
        return false;
    }
};
