class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i < m; ++i){
            int l = 0;
            int r = n-1;
            int mid;
            while(l <= r){
                mid = l + (r-l)/2;
                if(matrix[i][mid] > target)
                    r = mid-1;
                else if(matrix[i][mid] < target)
                    l = mid+1;
                else
                    return true;
            }
        }
        return false;
    }
};