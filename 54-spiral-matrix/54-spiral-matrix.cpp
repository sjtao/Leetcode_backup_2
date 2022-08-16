class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int q = m * n;
        vector<int> ans(q);
        
        int k = 0;
        int left = 0, right = n-1;
        int top = 0, bottom = m-1;
        while(k < q){
            for(int i = left; i <= right; i++)
                ans[k++] = matrix[top][i];
            top++;
            if(top > bottom) break;
            
            for(int i = top; i <= bottom; i++)
                ans[k++] = matrix[i][right];
            right--;
            if(right < left) break;
            
            for(int i = right; i >= left; i--)
                ans[k++] = matrix[bottom][i];
            bottom--;
            if(bottom < top) break;
            
            for(int i = bottom; i >= top; i--)
                ans[k++] = matrix[i][left];
            left++;
            if(left > right) break;
        }
        
        return ans;
    }
};