class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> ed(n);
        for(int i = 0; i < edges.size(); i++){
            // bi-directional graph 
            ed[edges[i][0]].push_back(edges[i][1]);
            ed[edges[i][1]].push_back(edges[i][0]);
        }
        //bfs
        queue<int> q;
        q.push(source);
        vector<bool> visited(n,0);
        visited[source] = 1;
        while(!q.empty()){
            int s = q.front(); q.pop();
            
            if(s == destination)
                return true;
            
            for(int i : ed[s]){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = 1;
                }                  
            }
        }
        
        return false;
    }
};