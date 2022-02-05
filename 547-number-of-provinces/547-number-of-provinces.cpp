class Solution {
public:
    vector<int> root, rank;
    int find(int x){
        if (x == root[x])
            return x;
        return root[x] = find(root[x]);
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
                rank[rootx] ++;
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        for(int i = 0; i < n; ++i){
            root.push_back(i);
            rank.push_back(1);
        }
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(isConnected[i][j] && i != j){
                    int x = find(i);
                    int y = find(j);
                    unionset(x, y);
                }
            }
        }
        
        int group = 0;
        for(int i = 0; i < n; i++){
            if(root[i] == i)
                group++;
        }
        
        return group;
        
    }
};