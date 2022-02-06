class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        //bfs
        int n = grid.size();
        if(n == 1 && grid[0][0] == 0)
            return 1;
        
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0)
            return -1;
        
        vector<vector<pair<int,int>>> cord;
        vector<pair<int,int>> path;
        path.push_back({0,0});
        queue<vector<pair<int,int>>> q;
        q.push(path);
        
        pair<int, int> dirs[8] = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
        vector<vector<int>> visited(n, vector<int>(n,0));
        visited[0][0] = 1;
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            
            auto te = t.back();
            for(int i = 0; i < 8; i++){
                int x = te.first + dirs[i].first;
                int y = te.second + dirs[i].second;
                if(x < 0 || y < 0 || x > n-1 || y > n-1 || grid[x][y] == 1 || visited[x][y] == 1)
                    continue;
                t.push_back({x, y});
                visited[x][y] = 1;
                if(x == n-1 && y == n-1)
                    cord.push_back(t);
                else
                    q.push(t);
                t.pop_back();
            }
        }
        
        int mx = INT_MAX;
        for(int i = 0; i < cord.size(); i++){
            if(mx > cord[i].size())
                mx = cord[i].size();
        }
        
        return mx == INT_MAX ? -1 : mx;
    }
};