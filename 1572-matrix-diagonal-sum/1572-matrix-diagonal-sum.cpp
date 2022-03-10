class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;
        for(int i = 0; i < n; ++i){
            if(i == n-i-1)
                sum += mat[i][i];
            else
                sum += (mat[i][i] + mat[i][n-1-i]);
        }
        return sum;
    }
};