/**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Pascal's Triangle.
Memory Usage: 6.3 MB, less than 99.69% of C++ online submissions for Pascal's Triangle.
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal(numRows);
        
        for(int i = 0; i < numRows; i++){
            pascal[i].resize(i+1);
            pascal[i][0] = 1;
            pascal[i][i] = 1;
            
            for(int j = 1; j < i; j++){
                pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j]; 
            }         
        }
        
        return pascal;
    }
};

/**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Pascal's Triangle.
Memory Usage: 6.3 MB, less than 99.65% of C++ online submissions for Pascal's Triangle.
*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans(numRows);
        int i = 0;
        while(i < numRows){
            ans[i] = vector<int>(i+1);
            if(i == 0)          
                ans[0][0] = 1;
            else{
                ans[i][0] = 1;
                ans[i][i] = 1;
                for(int j = 1; j < i; j++){
                    ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
                }
            }
            i++;
                
        }

        return ans;
        
    }
};
