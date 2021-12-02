/**
Runtime: 24 ms, faster than 91.71% of C++ online submissions for Diagonal Traverse.
Memory Usage: 18.5 MB, less than 44.76% of C++ online submissions for Diagonal Traverse.
*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
        int m = mat.size(); // row
        int n = mat[0].size(); // col
        int d = m + n - 1; // number of diagonals
        
        // m = 3, n = 4 matrix
        // * * * *
        // * * * *
        // * * * *
        // 0: [0,0]
        // 1: [0,1] [1,0]
        // 2: [2,0] [1,1] [0,2]
        // 3: [0,3] [1,2] [2,1]
        // 4: [2,2] [1,3]
        // 5: [2,3]
        vector<int> diag;
        
        int c = 0, row , col;
        while (c < d){
            if(c % 2 == 1){//odd
                col =min(c, n-1);
                while(col >= 0 && c-col < m){
                    diag.push_back(mat[c-col][col]);
                    col--;
                }
            }
            else{//even
                row = min(c, m-1);
                while(row >= 0 && c-row < n){
                    diag.push_back(mat[row][c-row]);
                    row--;
                }
            }
            
            c++;
        }
        return diag;
        
    }
};
