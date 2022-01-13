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