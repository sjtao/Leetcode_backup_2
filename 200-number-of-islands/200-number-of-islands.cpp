class Solution {
public:
    int island, m, n;
    vector<int> root, rank;
    pair<int,int> dirs[4] = {{0,1}, {0,-1}, {1,0},{-1,0}};
    
    int find(int x){
        if(x == root[x])
            return x;
        return root[x] = find(root[x]);
    }
    
    void unionset(int x, int y){
        int fx = find(x);
        int fy = find(y);
        if(fx != fy){
            if(rank[fx] > rank[fy])
                root[fy] = fx;
            else if(rank[fx] < rank[fy])
                root[fx] = fy;
            else{
                root[fx] = fy;
                rank[fy]++;
            }
            island --;
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        island = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == '1'){
                    root.push_back(i * n + j);
                    rank.push_back(1);
                    island++;
                }
                else{
                    root.push_back(-1);
                    rank.push_back(0);
                }
            }
        }
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == '1'){
                    grid[i][j] = '0';
                    for(int k = 0; k < 4; k++){
                        int kx = i + dirs[k].first;
                        int ky = j + dirs[k].second;
                        if(kx < 0 || ky < 0 || kx >= m || ky >= n || grid[kx][ky] == '0')
                            continue;
                        unionset(i*n+j, kx*n+ky);
                    }
                }
            }
        }
        
        return island;
    }
};