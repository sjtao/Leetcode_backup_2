class Solution {
public:
    int find(vector<int>& parent, int x){
        return parent[x] == x ? x : find(parent, parent[x]);
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        int group = n;
        
        vector<int> parent(n);
        for(int i = 0; i < n; i++)
            parent[i] = i;
        
        for(int i = 0; i < m; i++){
            int p1 = find(parent, edges[i][0]);
            int p2 = find(parent, edges[i][1]);
            if(p1 != p2){
                parent[p1] = p2;
                group--;
            }
        }
        return group;
    }
};