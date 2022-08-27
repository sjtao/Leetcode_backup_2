class Solution {
public:
    void rotate(vector<vector<int>>& A) {
        //diagonal: A[i][j] <--> A[j][i]
        int n = A.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int tem = A[i][j];
                A[i][j] = A[j][i];
                A[j][i] = tem;
            }
        }
        
        //reverse each row
        for(int i = 0; i < n; i++)
            reverse(A[i].begin(), A[i].end());
        
        return;
    }
};