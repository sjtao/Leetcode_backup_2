class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0, r = m*n-1, k;
        while(l <= r){
            k = l + (r - l) / 2;
            int row = k / n;
            int col = k % n;
            if(matrix[row][col] < target)
                l = k + 1;
            else if(matrix[row][col] > target)
                r = k - 1;
            else
                return true;
        }
        return false;
    }
};