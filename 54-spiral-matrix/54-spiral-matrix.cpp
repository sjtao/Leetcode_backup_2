class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> spiral(m*n);
        
        int left = 0, right = n-1;
        int top = 0, bottom = m-1;
        int k = 0;
        while(k < m*n){
            for(int i = left; i <= right; i++)
                spiral[k++] = matrix[top][i];
            top++;
            if(top > bottom) break;
            
            for(int i = top; i <= bottom; i++)
                spiral[k++] = matrix[i][right];
            right--;
            if(right < left) break;
            
            for(int i = right; i >= left; i--)
                spiral[k++] = matrix[bottom][i];
            bottom--;
            if(bottom < top) break;
            
            for(int i = bottom; i >= top; i--)
                spiral[k++] = matrix[i][left];
            left++;
            if(left > right) break;
        }
        
        return spiral;
    }
};