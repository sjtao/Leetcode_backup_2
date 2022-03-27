class Solution {
public:
    int sum(vector<int>& a){
        int s = 0;
        for(int x : a){
            if(x == 0)
                break;
            s += x;
        }
        return s;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>> q;
        int m = mat.size();
        for(int i = 0; i < m; i++){
            q.push({sum(mat[i]), i});
            if(q.size()>k)
                q.pop();
        }
        
        vector<int> ans(k);
        while(!q.empty()){
            ans[--k] = q.top().second;
            q.pop();
        }
        
        return ans;
    }
};