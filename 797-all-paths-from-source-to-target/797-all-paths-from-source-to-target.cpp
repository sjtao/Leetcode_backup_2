class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        if(n == 0)
            return ans;
        
        queue<vector<int>> q;
        vector<int> path;
        path.push_back(0);
        q.push(path);
        
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            int s = t.back();
            for(int i : graph[s]){       
                t.push_back(i);
                if(t.back() == n-1)
                    ans.push_back(t);
                else
                    q.push(t);
                t.pop_back();
            }
        }
        
        return ans;
    }
};