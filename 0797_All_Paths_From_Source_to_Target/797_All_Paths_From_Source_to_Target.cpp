/**
Runtime: 8 ms, faster than 96.19% of C++ online submissions for All Paths From Source to Target.
Memory Usage: 10.7 MB, less than 71.28% of C++ online submissions for All Paths From Source to Target.
*/
class Solution {
public:
    int n;
    
    void path(vector<vector<int>>& graph, vector<vector<int>>& ans, vector<int>& pa, int i){
        if(i == n-1){
            ans.push_back(pa);
            return;
        }
        
        for(int j = 0; j < graph[i].size(); j++){
            pa.push_back(graph[i][j]);
            path(graph, ans, pa, graph[i][j]);
            pa.pop_back();
        }
        
        return;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        vector<vector<int>> ans;
        vector<int> pa;
        pa.push_back(0); //starting from zero;
        path(graph, ans, pa, 0);
        return ans;
    }
};
