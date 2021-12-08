/**
Runtime: 92 ms, faster than 91.33% of C++ online submissions for Search a 2D Matrix II.
Memory Usage: 15 MB, less than 21.84% of C++ online submissions for Search a 2D Matrix II.
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int row = m-1, col = 0;
        //Search Space Reduction
        while(row >= 0 && col < n){
            if(matrix[row][col] > target){
                row--;
            }else if(matrix[row][col] < target){
                col++;
            }else{
                return true;
            }
        }
        return false;
    }
};
