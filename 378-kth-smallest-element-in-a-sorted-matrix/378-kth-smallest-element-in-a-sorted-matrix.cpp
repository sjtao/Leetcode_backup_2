class Solution {
public:
    int n;
    int count(vector<vector<int>>& matrix, vector<int>& minmax, int m){
        int num = 0;
        int col = 0, row = n-1;
        while(row >= 0 && col < n){
            if(matrix[row][col] > m){
                minmax[1] = min(minmax[1], matrix[row][col]);
                row--;
            }
            else{
                minmax[0] = max(minmax[0], matrix[row][col]);
                col++;
                num += (row+1);
            }
        }
        return num;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        n = matrix.size();
        int l = matrix[0][0], r = matrix[n-1][n-1], m;
        
        int num;
        while(l < r){
            m = l + (r - l) / 2;
            vector<int> minmax = {l, r};
            num = count(matrix, minmax, m);
            if(num == k)
                return minmax[0];
            else if(num > k)
                r = minmax[0];
            else
                l = minmax[1];
        }
        
        return l;
    }
};