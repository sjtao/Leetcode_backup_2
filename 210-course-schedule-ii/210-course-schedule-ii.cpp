class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> indg(n, 0);
        vector<vector<int>> g(n);
        for(auto p : prerequisites){
            indg[p[0]]++;
            g[p[1]].push_back(p[0]); //out from p[0] to p[1] edge
        }
        
        queue<int> q;
        for(int i = 0; i < n; ++i){
            if(indg[i] == 0)
                q.push(i);
        }
        
        vector<int> ans;
        while(!q.empty()){
            int c = q.front();
            q.pop();
            ans.push_back(c);
            for(int p : g[c]){
                indg[p]--;
                if(indg[p] == 0)
                    q.push(p);
            }
        }
        
        if(ans.size() != n) ans.clear(); //unable to finish all courses
        
        return ans;
        
    }
};