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
        int m = mat.size();
        vector<vector<int>> q(m, vector<int>(2));
        for(int i = 0; i < m; ++i){
            q[i][0] = sum(mat[i]);
            q[i][1] = i;
        }
        
        sort(q.begin(), q.end());
        
        vector<int> ans(k);
        for(int i = 0; i < k; ++i)
            ans[i] = q[i][1];
        
        return ans;
    }
};