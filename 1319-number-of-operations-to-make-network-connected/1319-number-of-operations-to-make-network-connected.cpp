class Solution {
public:
    vector<int> root, rank;
    int find(int x){
        if(x == root[x])
            return x;
        return root[x] = find(root[x]);
    }
    
    void unionset(int x, int y){
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
        }
    }
    
    bool connection(int x, int y){
        return find(x) == find(y);
    }
        
    int makeConnected(int n, vector<vector<int>>& connections) {
        int cn = connections.size();
        if(cn < n-1) return -1;
        
        for(int i = 0; i < n; i++){
            root.push_back(i);
            rank.push_back(1);
        }
        
        for(auto c : connections){
            unionset(c[0], c[1]);
        }
        
        set<int> s;
        for(int i : root)
            s.insert(find(i));
        
        return s.size()-1;
    }
};