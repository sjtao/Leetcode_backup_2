class Solution {
public:

    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int n = routes.size();
   
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++){
            for(int j : routes[i]){
                mp[j].push_back(i);
            }
        }
        
        queue<pair<int,int>> q;
        q.push({source, 0});
        
        unordered_set<int> visited;
        visited.insert(source);
        
        while(!q.empty()){
            int s = q.front().first;
            int r = q.front().second;
            q.pop();
            if(s == target)
                return r;
            
            for(int i : mp[s]){
                for(int j : routes[i]){
                    if(visited.find(j) == visited.end()){
                        visited.insert(j);
                        q.push({j, r+1});
                    }
                }
                routes[i].clear();
            }
        }
        
        return -1;
    }
};