class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int l = 0, r = n-1;
        int t = 0, b = m-1;
        vector<int> res(m*n);
        int k = 0;
        while(k < m*n){
            for(int i = l; i <= r; i++)
                res[k++] = matrix[t][i];
            t++;
            if(t > b) break;
            
            for(int i = t; i <= b; i++)
                res[k++] = matrix[i][r];
            r--;
            if(r < l) break;
            
            for(int i = r; i >= l; i--)
                res[k++] = matrix[b][i];
            b--;
            if(b < t) break;
            
            for(int i = b; i >= t; i--)
                res[k++] = matrix[i][l];
            l++;
            if(l > r) break;
        }
        
        return res;
    }
};