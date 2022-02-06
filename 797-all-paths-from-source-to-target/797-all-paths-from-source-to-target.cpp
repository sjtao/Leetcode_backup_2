class Solution {
public:
    int n;
    void helper(vector<vector<int>>& graph, vector<vector<int>>& ans, vector<int>& g, int k){
        if(k == n-1){
            ans.push_back(g);
            return;
        }
            
        
        for(int i = 0; i < graph[k].size(); i++){
            g.push_back(graph[k][i]);
            helper(graph, ans, g, graph[k][i]);
            g.pop_back();
        }
        return;
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        vector<vector<int>> ans;
        vector<int> g;
        g.push_back(0);
        helper(graph, ans, g, 0);
        return ans;
    }
};