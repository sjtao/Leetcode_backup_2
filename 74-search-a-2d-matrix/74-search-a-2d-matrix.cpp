class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0, r = n*m-1, k;
        while(l <= r){
            k = l + (r-l)/2;
            if(matrix[k/n][k%n] == target)
                return true;
            else if(matrix[k/n][k%n] > target)
                r = k-1;
            else
                l = k+1;
        }
        return false;
    }
};