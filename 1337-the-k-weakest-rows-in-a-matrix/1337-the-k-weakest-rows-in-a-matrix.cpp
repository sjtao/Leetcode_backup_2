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
        int n = mat[0].size();
        
        vector<int> ans;
        set<int> st;
        
        for(int j = 0; j < n; ++j){
            for(int i = 0; i < m; ++i){
                if(mat[i][j] == 0 && !st.count(i)){
                    st.insert(i);
                    ans.push_back(i);
                }
                if(ans.size() == k)
                    return ans;
            }
        }
        
        //if ans.size() < k, rest rows all 1
        for(int i = 0; i < m; ++i){
            if(!st.count(i) && ans.size()<k)
                ans.push_back(i);
        }
        
        return ans;
    }
};