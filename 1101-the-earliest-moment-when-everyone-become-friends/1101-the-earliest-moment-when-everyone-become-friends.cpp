class Solution {
public:
    vector<int> root, rank;
    int find(int x){
        if(x == root[x])
            return x;
        return root[x] = find(root[x]);
    }
    
    void unionset(int x, int y, int &f){
        int fx = find(x);
        int fy = find(y);
        if(fx != fy){
            if(rank[fy] > rank[fx]){
                root[fx] = fy;
            }
            else if(rank[fy] < rank[fx]){
                root[fy] = fx;
            }
            else{
                root[fy] = fx;
                rank[fx] ++;
            }
            f--;
        }
        return;
    }
    
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end());
        
        for(int i = 0; i < n; i++){
            root.push_back(i);
            rank.push_back(1);
        }
        
        int f = n;
        for(int i = 0; i < logs.size(); i++){
            unionset(logs[i][1], logs[i][2], f);
            if(f == 1)
                return logs[i][0];
        }
        
        return -1;
    }
};