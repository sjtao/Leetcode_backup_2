class Solution {
public:
    pair<int,int> dir[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int m, n, initcolor;
    
    void dfs(vector<vector<int>>& image, int sr, int sc, int color){
        if(image[sr][sc] != initcolor)
            return;
        
        image[sr][sc] = color;
        for(int k = 0; k < 4; k++){
            int x = dir[k].first + sr;
            int y = dir[k].second + sc;
            if(x < 0 || y < 0 || x >= m || y >= n || image[x][y] != initcolor)
                continue;
            
            dfs(image, x, y, color);
        }
        
        return;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();
        initcolor = image[sr][sc];
        if(initcolor != color)
            dfs(image, sr, sc, color);
        return image;
    }
};