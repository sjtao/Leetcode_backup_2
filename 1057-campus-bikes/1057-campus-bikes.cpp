class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int n = workers.size();
        int m = bikes.size();
        vector<int> ans(n, -1);
        vector<bool> assigned(m, false);
        vector<pair<int,int>> dis[2000];
        int c = 0;
        int mind = 2000;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                c = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
                dis[c].push_back({i, j});
                mind = min(mind, c);
            }
        }
        
        int curd = mind;
        int pair = 0;
        while(pair < n){
            for(auto[w, b] : dis[curd]){
                if(ans[w] == -1 && !assigned[b]){
                    assigned[b] = true;
                    ans[w] = b;
                    pair++;
                }
            }
            curd ++;
        }
        
        return ans;
    }
};