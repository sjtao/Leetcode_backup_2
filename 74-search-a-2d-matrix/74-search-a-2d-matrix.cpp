class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0, r = m*n -1, d;
        int row, col;
        while(l <= r){
            d = l + (r - l) / 2;
            row = d / n;
            col = d % n;
            if(matrix[row][col] == target)
                return true;
            else if(matrix[row][col] > target)
                r = d - 1;
            else
                l = d + 1;
        }
        
        return false;
    }
};