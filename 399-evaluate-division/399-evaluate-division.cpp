class Solution {
public:
    unordered_map<string, unordered_map<string, double>> mp;
    double dfs(string a, string b,  unordered_set<string>& visited){
        if(mp.find(a) == mp.end())
            return -1;
        
        if(mp[a].find(b) != mp[a].end())
            return mp[a][b];
        
        for(auto& x : mp[a]){
            if(visited.find(x.first) != visited.end())
                continue;
            visited.insert(x.first);
            double res = dfs(x.first, b, visited);
            if(res != -1)
                return mp[a][b] = mp[a][x.first] * res;
        }
        
        return -1;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        int ne = equations.size();
        for(int i = 0; i < ne; i++){
            string& e1 = equations[i][0];
            string& e2 = equations[i][1];
            mp[e1][e1] = 1.0;
            mp[e2][e2] = 1.0;
            mp[e1][e2] = values[i];
            mp[e2][e1] = 1.0/values[i];
        }
        
        int n = queries.size();
        vector<double> ans;
        
        for(vector<string>& q : queries){
            unordered_set<string> visited;
            visited.insert(q[0]);
            ans.push_back(dfs(q[0], q[1], visited));
        }
        
        return ans;
    }
};