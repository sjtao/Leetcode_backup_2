class Solution {
public:
    int find(vector<int>& parent, int x){
        if(parent[x] == x)
            return x;
        return find(parent, parent[x]);
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> parent(n);
        
        for(int i = 0; i < n; i++)
            parent[i] = i;
        
        int group = n;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(isConnected[i][j]){
                    int p1 = find(parent, i);
                    int p2 = find(parent, j);
                    if(p1 != p2){ //belong to different groups and merge them
                        parent[p1] = p2;
                        group--;
                    }
                }
            }
        }
        
        return group;
    }
};