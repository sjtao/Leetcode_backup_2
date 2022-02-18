class Solution {
public:
    vector<int> root, rank;
    int find(int x){
        if(x == root[x])
            return x;
        return root[x] = find(root[x]);
    }
    
    void unionset(int x, int y, int& f){
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
            f--;
        }
        return;
    }
    
    bool connected(int x, int y){
        return find(x) == find(y);
    }
    
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end());
        
        for(int i = 0; i < n; ++i){
            root.push_back(i);
            rank.push_back(1);
        }
        
        int nf = n-1; //n-1 strangers at first
        for(auto v : logs){
            int t = v[0];
            int x = v[1];
            int y = v[2];
            unionset(x, y, nf);
            if(nf == 0)
                return t;
        }
        
        return -1;
    }
};