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
    
    int earliestAcq(vector<vector<int>>& logs, int n) {
        int ln = logs.size();
        int group = n;
        
        sort(logs.begin(), logs.end());
        
        for(int i = 0; i < n; i++){
            root.push_back(i);
            rank.push_back(1);
        }

        for(auto t : logs){
            unionset(t[1], t[2], group);
            if(group == 1)
                return t[0];
        }
        
        return -1;
    }
};