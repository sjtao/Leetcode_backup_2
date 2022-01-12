class Solution {
public:
    
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        //return all nodes with indegree = 0
        vector<int> in(n, 0), out(n, 0);
        int e = edges.size();
        for(int i = 0; i < e; i++){
            out[edges[i][0]]++;
            in[edges[i][1]]++;
        }
        
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(in[i] == 0 and out[i] != 0)
                ans.push_back(i);
        }
        
        return ans;
    }
};