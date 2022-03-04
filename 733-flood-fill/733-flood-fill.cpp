class Solution {
public:
    int m, n, color;
    pair<int,int> dirs[4] = {{0,1},{0,-1},{1,0},{-1,0}};
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        m = image.size();
        n = image[0].size();
        color = image[sr][sc];
        image[sr][sc] = newColor;
        vector<vector<int>> visited(m, vector<int>(n,0));
        visited[sr][sc] == 1;
        queue<pair<int,int>> q;
        q.push({sr, sc});
        while(!q.empty()){
            auto d = q.front(); 
            q.pop();
            int x = d.first;
            int y = d.second;
            for(int i = 0; i < 4; ++i){
                int ix = x + dirs[i].first;
                int iy = y + dirs[i].second;
                if(ix < 0 || iy < 0 || ix >= m || iy >= n || image[ix][iy] != color || visited[ix][iy])
                    continue;
                image[ix][iy] = newColor;
                visited[ix][iy] = 1;
                q.push({ix,iy});
            }
        }
        return image;
    }
};