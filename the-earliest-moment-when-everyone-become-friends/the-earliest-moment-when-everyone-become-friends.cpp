class Solution {
public:
    int find(vector<int>& parent, int x){
        return parent[x] == x ? x : find(parent, parent[x]);
    }
    
    int earliestAcq(vector<vector<int>>& logs, int n) {
        int m = logs.size();
        int group = n;
 
        sort(logs.begin(), logs.end());
        
        vector<int> parent(n);
        for(int i = 0; i < n; i++)
            parent[i] = i;
        
        for(int i = 0; i < m; i++){
            int p1 = find(parent, logs[i][1]);
            int p2 = find(parent, logs[i][2]);
            if(p1 != p2){
                parent[p1] = p2;
                group--;
                if(group == 1){
                    return logs[i][0];
                }
            }
        }
        
        return -1;
    }
};