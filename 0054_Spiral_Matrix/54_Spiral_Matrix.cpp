/**
Runtime: 5 ms, faster than 5.72% of C++ online submissions for Spiral Matrix.
Memory Usage: 6.9 MB, less than 70.43% of C++ online submissions for Spiral Matrix.
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<int> spiral;
        int left = 0, right = m-1, top = 0, bottom = n-1;
        int j;
        while(left <= right && top <= bottom){
            for(j = left; j <= right; j++){
                spiral.push_back(matrix[top][j]);
            }
            top++;
            if(top > bottom) break;
            
            for(j = top; j <= bottom; j++){
                spiral.push_back(matrix[j][right]);
            }
            right--;
            if(right < left) break;
            
            for(j = right; j >= left; j--){
                spiral.push_back(matrix[bottom][j]);
            }
            bottom--;
            if(bottom < top) break;
            
            for(j = bottom; j>= top; j--){
                spiral.push_back(matrix[j][left]);
            }
            left++;
            if(left > right) break;
        }
        
        return spiral;
    }
};
