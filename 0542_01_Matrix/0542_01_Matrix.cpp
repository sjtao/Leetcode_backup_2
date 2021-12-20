/**
Runtime: 64 ms, faster than 81.31% of C++ online submissions for 01 Matrix.
Memory Usage: 33.1 MB, less than 18.55% of C++ online submissions for 01 Matrix.
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        queue<pair<int, int>> q;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    visited[i][j] = 1;
                }
            }
        }
        
        pair<int, int> dirs[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int step = 0;
        while(!q.empty()){
            int s = q.size();
            while(s){
                auto p = q.front(); q.pop();s--;
                int px = p.first;
                int py = p.second;
                ans[px][py] = step;
                for(int i = 0; i < 4; i++){
                    int x = px + dirs[i].first;
                    int y = py + dirs[i].second;
                    if(x < 0 || x >= m || y < 0 || y >= n || visited[x][y])
                        continue;
                    visited[x][y] = 1;
                    q.push({x,y});
                }
            }
            step ++;
        }
        return ans;
    }
};
