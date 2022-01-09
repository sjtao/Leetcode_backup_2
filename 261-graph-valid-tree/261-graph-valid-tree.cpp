class Solution {
public:
    int find(vector<int>& parent, int x){
        return parent[x] == x ? x : find(parent, parent[x]);
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        //tree; any connected graph without simple cycles is a tree
        vector<int> parent(n);
        for(int i = 0; i < n; i++)
            parent[i] = i;
        
        for(int i = 0; i < edges.size(); i++){
            int p1 = find(parent, edges[i][0]);
            int p2 = find(parent, edges[i][1]);
            if(p1 != p2)
                parent[p1] = p2;
            else 
                return false; // cycle
        }
        
        return edges.size() == n-1; //every node is connected 
    }
};