class Solution {
public:
    vector<int> rank, parent;
    
    int find(int x){
        if(x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }
    
    void unionfind(int x, int y){
        int fx = find(x);
        int fy = find(y);
        if(fx == fy) return;
        else{
            if(rank[fx] > rank[fy]){
                parent[fy] = fx;
            }
            else if(rank[fx] < rank[fy]){
                parent[fx] = fy;
            }
            else{
                parent[fy] = fx;
                rank[fx] ++;
            }
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        
        for(int i = 0; i < n; i++){
            parent.push_back(i);
            rank.push_back(1);
        }
        
        for(auto p : pairs)
            unionfind(p[0], p[1]);
        
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++)
            mp[find(i)].push_back(i);
        
        for(auto p: mp){
            string t = "";
            for(int i : p.second)
                t += s[i];
            sort(t.begin(), t.end());
            int k = 0;
            for(int i = 0; i < t.size(); i++)
                s[p.second[i]] = t[i];
        }
        
        return s;
    }
};