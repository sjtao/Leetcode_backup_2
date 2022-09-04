class Solution {
public:
    vector<int> root, rank;
    
    int find(int x){
        while(x != root[x])
            x = root[x];
        return x;
    }
    
    void unionset(int x, int y){
        int rootx = find(x);
        int rooty = find(y);
        if(rootx != rooty){
            if(rank[rootx] > rank[rooty])
                root[rooty] = rootx;
            else if(rank[rootx] < rank[rooty])
                root[rootx] = rooty;
            else{
                root[rooty] = rootx;
                rank[rootx]++;
            }
        }
    }
    
    bool connected(int x, int y){
        return find(x) == find(y);
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        root = vector<int>(n);
        rank = vector<int>(n, 0);
        
        for(int i = 0; i < n; i++){
            root[i] = i;
            rank[i] = 1;
        }
        
        int province = n;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j]){
                    int a = find(i);
                    int b = find(j);
                    if(a != b){
                        root[a] = b;
                        province--;
                    }
                }
            }
        }
        
        return province;
    }
};