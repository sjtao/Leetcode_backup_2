class Solution {
public:
    pair<int,int> dir[4] = {{1,0},{0,1},{0,-1},{-1,0}};
    int m, n;
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        m = heights.size();
        n = heights[0].size();
        
        queue<pair<int,int>> pf, at;
        for(int i = 0; i < n; i++){
            pf.push({0,i});
            at.push({m-1, i});
        }
        for(int i = 0; i < m; i++){
            pf.push({i,0});
            at.push({i,n-1});
        }
        
        vector<vector<bool>> paf, atl;
        paf = bfs(heights, pf);
        atl = bfs(heights, at);
        
        vector<vector<int>> res;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(paf[i][j] && atl[i][j])
                    res.push_back({i,j});
            }
        }
        
        return res;
    }
    
    vector<vector<bool>> bfs(vector<vector<int>>& heights, queue<pair<int,int>>& q){
        vector<vector<bool>> flow(m, vector<bool>(n, false));
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            flow[x][y] = true;
            for(int i = 0; i < 4; i++){
                int ix = x + dir[i].first;
                int iy = y + dir[i].second;
                if(ix < 0 || ix >= m || iy < 0 || iy >= n || flow[ix][iy] || heights[ix][iy] < heights[x][y])
                    continue;
                
                q.push({ix, iy});
            }
        }
        return flow;
    }
};