class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n,0));
        int t = 0, b = n-1, l = 0, r = n-1;
        int cnt = 1;
        while(t <= b && l <= r){
            //left
            for(int i = l; i <= r; i++){
                ans[t][i] = cnt++;
            }
            t++;
            
            //down
            for(int i = t; i <= b; i++){
                ans[i][r] = cnt++;
            }
            r--;
            
            //right
            for(int i = r; i >= l; i--){
                ans[b][i] = cnt++;
            }
            b--;
            
            //up
            for(int i = b; i >= t; i--){
                ans[i][l] = cnt++;
            }
            l++;
        }
        
        return ans;
    }
};