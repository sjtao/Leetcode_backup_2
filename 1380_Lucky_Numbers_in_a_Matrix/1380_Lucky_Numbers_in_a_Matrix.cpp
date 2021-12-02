/**
Runtime: 20 ms, faster than 86.72% of C++ online submissions for Lucky Numbers in a Matrix.
Memory Usage: 11.3 MB, less than 92.06% of C++ online submissions for Lucky Numbers in a Matrix.
*/

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int i = 0, j;
        while(i < m){
            //find minimum element in i-th row
            int mn = matrix[i][0];
            int idn = 0;
            for(j = 1; j < n; j++){
                if(mn > matrix[i][j]){
                    mn = matrix[i][j];
                    idn = j;
                }
            }
            //check maximum in idn-th col   
            for(j = 0; j < m; j++){
                if(matrix[j][idn] > mn){
                    break;
                }
            }
            
            if(j == m){
                ans.push_back(mn);
            }
            
            i++;
        }
        
        return ans;
    }
};
