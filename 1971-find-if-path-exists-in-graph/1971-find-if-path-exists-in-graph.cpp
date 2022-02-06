class Solution {
public:
    vector<int> root, rank;
    
    int find(int x){
        if(x == root[x])
            return x;
        return root[x] = find(root[x]);
    }
    
    void unionset(int x, int y){
        int ux = find(x);
        int uy = find(y);
        if(ux != uy){
            if(rank[ux] > rank[uy])
                root[uy] = ux;
            else if(rank[uy] > rank[ux])
                root[ux] = uy;
            else{
                root[uy] = ux;
                rank[ux]++;
            }
        }
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        for(int i = 0; i < n; i++){
            root.push_back(i);
            rank.push_back(1);
        }
        
        for(int i = 0; i < edges.size(); i++){
            unionset(edges[i][0], edges[i][1]);
        }
        
        return find(source) == find(destination);
    }
};