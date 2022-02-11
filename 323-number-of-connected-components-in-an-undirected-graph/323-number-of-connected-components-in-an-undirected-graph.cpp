class Solution {
public:
    vector<int> root, rank;
    int find(int x){
        if(x == root[x])
            return x;
        return root[x] = find(root[x]);
    }
    
    void unionset(int x, int y, int& group){
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
            group--;
        }
    }
    
    bool connection(int x, int y){
        return find(x) == find(y);
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        for(int i = 0; i < n; i++){
            root.push_back(i);
            rank.push_back(1);
        }
        int group = n;
        for(auto e : edges){
            unionset(e[0], e[1], group);
        }
        return group;
    }
};