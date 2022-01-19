class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        int ed = edges.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < ed; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        stack<int> s;
        s.push(source);
        vector<bool> visited(n);
        
        while(!s.empty()){
            int a = s.top(); s.pop();
            
            if(a == destination)
                return true;
            
            if(visited[a] == true)
                continue;
            
            visited[a] = true;
            for(int i : adj[a])
                s.push(i);
        }
        return false;
    }
};