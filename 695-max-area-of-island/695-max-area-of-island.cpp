class Solution {
public:
    vector<int> root, rank, size;
    int find(int x){
        if(x == root[x])
            return x;
        return root[x] = find(root[x]);
    }
    
    void unionset(int x, int y){
        int rx = find(x);
        int ry = find(y);
        if(rx != ry){
            if(rank[rx] > rank[ry]){
                root[ry] = rx;
                size[rx] += size[ry];
            }   
            else if(rank[rx] < rank[ry]){
                root[rx] = ry;
                size[ry] += size[rx];
            }     
            else{
                root[rx] = ry;
                rank[ry] ++;
                size[ry] += size[rx];
            }
        }

        return;
    }
    
    pair<int,int> dirs[4] = {{0,1},{0,-1},{1,0},{-1,0}};
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1){
                    root.push_back(i * n + j);
                    rank.push_back(1);
                    size.push_back(1);
                }
                else{
                    root.push_back(-1);
                    rank.push_back(-1);
                    size.push_back(-1);
                }
                
            }
        }
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1){
                    for(int k = 0; k < 4; ++k){
                        int kx = i + dirs[k].first;
                        int ky = j + dirs[k].second;
                        if(kx < 0 || ky < 0 || kx >= m || ky >= n)
                            continue;
                        if(grid[kx][ky] == 1)
                            unionset(i*n+j, kx*n+ky);
                    }
                }
            }
        }
        int ans = *max_element(size.begin(), size.end());
        return ans == -1 ? 0 : ans;
    }
};