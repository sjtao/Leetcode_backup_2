class Solution {
public:
    vector<int> parent;
    int find(int x){
        return parent[x] == x ? x : find(parent[x]);
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        for(int i = 0; i < n; i++)
            parent.push_back(i);
        
        int ed = edges.size();
        for(int i = 0; i < ed; i++){
            int a = find(edges[i][0]);
            int b = find(edges[i][1]);
            if(a != b){
                parent[a] = b;
            }
        }
        
        return find(parent[source]) == find(parent[destination]);
    }
};