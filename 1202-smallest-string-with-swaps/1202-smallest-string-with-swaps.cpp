class Solution {
public:
    static const int N = 100001;
    vector<int> adj[N];
    bool visited[N];
    
    void dfs(string&s, int vertex, vector<char>& characters, vector<int> &  indices){
        characters.push_back(s[vertex]);
        indices.push_back(vertex);
        
        visited[vertex] = true;
        
        for(int adjacent : adj[vertex]){
            if(!visited[adjacent])
                dfs(s, adjacent, characters, indices);
        }
        
        return;
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        //build adjacent list
        for(vector<int> p : pairs){
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }
        
        for(int v = 0; v < s.size(); v++){
            if(!visited[v]){
                vector<char> cha;
                vector<int> ind;
                
                dfs(s, v, cha, ind);
                
                sort(cha.begin(), cha.end());
                sort(ind.begin(), ind.end());
                
                for(int i = 0; i < ind.size(); i++){
                    s[ind[i]] = cha[i];
                }
            }
        }
        
        return s;
    }
};