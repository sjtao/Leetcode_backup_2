class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0, r = m*n-1;
        while(l <= r){
            int d = l + (r-l)/2;
            if(matrix[d/n][d%n] == target)
                return true;
            else if(matrix[d/n][d%n] > target)
                r = d-1;
            else
                l = d+1;
        }
        return false;
    }
};