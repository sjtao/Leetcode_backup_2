class Solution {
public:
    vector<pair<int, int>> net[101];
    int mntime;
    
    void dfs(vector<int>& recv, int n, int k, int w){
        if(w >= recv[k])
            return;
        
        recv[k] = w;
        
        for(pair<int,int> p : net[k]){
            dfs(recv, n, p.first, w+p.second);
        }
        
        return;
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for(vector<int> p : times)
            net[p[0]].push_back({p[1], p[2]});
        
        for(int i = 1; i <= n; i++)
            sort(net[i].begin(), net[i].end());
        
        vector<int> recv(101, INT_MAX);
        dfs(recv, n, k, 0);
        
        int mntime = INT_MIN;
        for(int i = 1; i <= n; i++)
            mntime = max(recv[i], mntime);
        
        return mntime == INT_MAX ? -1 : mntime;
    }
};