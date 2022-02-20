class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        //matrix sorted left ->right, top->bottom
        if(target < matrix[0][0] || target > matrix[m-1][n-1])
            return false;
        
        int row = -1;
        for(row = 0; row < m; row++){
            int l = 0, r = n-1, p;
            while(l <= r){
                p = l + (r - l)/2;
                if(matrix[row][p] > target)
                    r = p-1;
                else if(matrix[row][p] < target)
                    l = p+1;
                else
                    return true;
            }
        }
        
        
        return false;
    }
};