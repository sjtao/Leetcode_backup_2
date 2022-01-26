class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        //BFS
        int m = rooms.size();
        int n = rooms[0].size();
        int INF = 2147483647;
        vector<pair<int,int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        queue<pair<int,int>> q;
        
        //save all the gate coordinates
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(rooms[i][j] == 0)
                    q.push({i,j});
            }
        }
        
        while(!q.empty()){
            auto it = q.front(); q.pop();
            for(int i = 0; i < 4; i++){
                int x = it.first + dirs[i].first;
                int y = it.second + dirs[i].second;
                if(x < 0 || y < 0 || x >= m || y >= n || rooms[x][y] != INF)
                    continue;
                rooms[x][y] = rooms[it.first][it.second] + 1;
                q.push({x,y});
            }
        }
        
        return;
        
    }
};