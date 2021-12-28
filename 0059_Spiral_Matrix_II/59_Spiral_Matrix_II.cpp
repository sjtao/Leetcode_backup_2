/**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Spiral Matrix II.
Memory Usage: 6.6 MB, less than 16.73% of C++ online submissions for Spiral Matrix II.
*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int c = 1;
        vector<pair<int, int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int i = 0, j = 0, k = 0;
        while(c <= n*n){
            ans[i][j] = c++;
            int nr = i + dir[k].first;
            int nc = j + dir[k].second;
            if(nr < 0 || nr >= n || nc < 0 || nc >= n || ans[nr][nc] != 0) k = (k+1)%4;
            i += dir[k].first;
            j += dir[k].second;
        }
        return ans;
    }
};
