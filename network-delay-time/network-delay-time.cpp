class Solution {
public:
    vector<pair<int,int>> adj[101];
    void dijkstra(vector<int>&signal, int source, int n){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0, source});
        signal[source] = 0;
        
        while(!pq.empty()){
            int curtime = pq.top().first;
            int curnode = pq.top().second;
            pq.pop();

            if(curtime > signal[curnode])
                continue;
            
            for(pair<int,int> edge : adj[curnode]){
                int time = edge.first;
                int next = edge.second;
                
                if(signal[next] > curtime + time){
                    signal[next] = curtime + time;
                    pq.push({signal[next], next});
                }
            }
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for(auto t : times){
            adj[t[0]].push_back({t[2], t[1]});
        }
        
        vector<int> signal(n+1, INT_MAX);
        dijkstra(signal, k, n);
        
        int ans = INT_MIN;
        for(int i = 1; i <= n; i++){
            ans = max(ans, signal[i]);
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};