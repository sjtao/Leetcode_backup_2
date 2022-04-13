class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> s(n*m);
        int t = 0, b = m-1, l = 0, r = n-1;
        int cnt = 0;
        while(cnt < n*m){
            //left
            for(int i = l; i <= r; i++)
                s[cnt++] = matrix[t][i];
            t++;
            if(t > b)
                break;
            
            //down
            for(int i = t; i <= b; i++)
                s[cnt++] = matrix[i][r];
            r--;
            if(r < l)
                break;
            
            //right
            for(int i = r; i >= l; i--)
                s[cnt++] = matrix[b][i];
            b--;
            if(b < t)
                break;
            //up
            for(int i = b; i >= t; i--)
                s[cnt++] = matrix[i][l];
            l++;
            if(l > r)
                break;
        }
        return s;
    }
};