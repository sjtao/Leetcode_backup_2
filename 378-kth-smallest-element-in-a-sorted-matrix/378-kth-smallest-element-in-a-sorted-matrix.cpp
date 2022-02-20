class Solution {
public:
    int n;
    int numbersmallerthanm(vector<vector<int>>& matrix, int m){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(matrix[i][n-1] <= m)
                cnt += n;
            else if(matrix[i][0] > m)
                continue;
            else{
                int j = n-1;
                while(j >= 0 && matrix[i][j] > m){
                    j--;
                }
                cnt += j+1;
            }
        }
        return cnt;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        n = matrix.size();
        int l = matrix[0][0];
        int r = matrix[n-1][n-1];
        int m, count;
        while(l <= r){
            m = l + (r - l) / 2;
            count = numbersmallerthanm(matrix, m);
            if(count >= k)
                r = m-1;
            else if(count < k)
                l = m+1;
        }
        
        return l;
        
    }
};