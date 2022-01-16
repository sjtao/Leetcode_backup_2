class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
         map<int, vector<int>> mp;
        int n = colors.size();
        for(int i = 0; i < n; ++i){
            mp[colors[i]].push_back(i);
        }
        
        int q = queries.size();
        vector<int> dis(q,0);
        for(int k = 0; k < q; ++k){
            int i = queries[k][0];
            int c = queries[k][1];
            if(mp.find(c) == mp.end()){
                dis[k] = -1;
            }
            else{//binary search                
                int l = 0, r = mp[c].size() - 1, m;
                while(l < r){
                    m = l + (r - l)/2;
                    if(mp[c][m] - i > 0) r = m;
                    else l = m+1;
                }
                if(l == 0) dis[k] = abs(mp[c][0] - i);
                else if(l == mp[c].size()) dis[k] = abs(mp[c][r] - i);
                else dis[k] = min(abs(mp[c][l-1] - i),abs(mp[c][r] - i));
            }
        }
        return dis;
    }
};