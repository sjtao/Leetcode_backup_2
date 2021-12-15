/**
Runtime: 19 ms, faster than 9.29% of C++ online submissions for Reshape the Matrix.
Memory Usage: 10.7 MB, less than 56.40% of C++ online submissions for Reshape the Matrix.
*/

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int mr = mat.size();
        int mc = mat[0].size();
        if((mr == 0) || (mr == r && mc == c) || (mc * mr != r * c)) 
            return mat;
        
        vector<vector<int>> ans(r);
        queue<int> mq;
        for(auto m : mat){
            for(int n : m){
                mq.push(n);
            }
        }
            
        
        for(int i = 0; i < r; i++){
            ans[i] = vector<int>(c);
            for(int j = 0; j < c; j++){
                ans[i][j] = mq.front();
                mq.pop();
            }
        }
        
        return ans;
    }
};
