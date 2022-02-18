class Solution {
public:
    vector<int> root, rank;
    pair<int,int> dirs[4] = {{0,1},{1,0},{-1,0},{0,-1}};
    
    int find(int x){
        if(x == root[x])
            return x;
        return root[x] = find(root[x]);
    }
    void unionset(int x, int y, int& g){
        int rx = find(x);
        int ry = find(y);
        if(rx != ry){
            if(rank[rx] > rank[ry])
                root[ry] = rx;
            else if(rank[rx] < rank[ry])
                root[rx] = ry;
            else{
                root[rx] = ry;
                rank[ry]++;
            }
            g--;
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m*n; ++i){
            root.push_back(i);
            rank.push_back(1);
        }
        int island = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == '1'){
                    island ++;
                    for(int k = 0; k < 4; ++k){
                        int x = i + dirs[k].first;
                        int y = j + dirs[k].second;
                        if(x < 0 || y < 0 || x >= m || y >= n)
                            continue;
                        if(grid[x][y] == '1')
                            unionset(i*n+j, x*n+y, island);
                    }
                }
            }
        }
        
        return island;
    }
};