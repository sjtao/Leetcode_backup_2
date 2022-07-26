class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int left = 0, right = n-1;
        int top = 0, bottom = m-1;
        vector<int> v(m*n);
        
        int k = 0;
        while(k < m*n){
            for(int i = left; i <= right; i++)
                v[k++] = matrix[top][i];
            top++;
            if(top > bottom) break;
            
            for(int i = top; i <= bottom; i++)
                v[k++] = matrix[i][right];
            right--;
            if(right < left) break;
            
            for(int i = right; i >= left; i--)
                v[k++] = matrix[bottom][i];
            bottom--;
            if(bottom < top) break;
            
            for(int i = bottom; i >= top; i--)
                v[k++] = matrix[i][left];
            left++;
            if(left > right) break;
        }
        
        return v;
    }
};