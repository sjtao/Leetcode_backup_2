class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        int n = encoded1.size();
        int m = encoded2.size();
        int i = 0, j = 0;
        vector<vector<int>> ans;
        int pre = 0;
        while(i < n && j < m){
            int mn = min(encoded1[i][1], encoded2[j][1]);
            int p = encoded1[i][0] * encoded2[j][0];
            if(p != pre)
                ans.push_back({p, mn});
            else
                ans.back()[1] += mn;
            
            encoded1[i][1] -= mn;
            if(encoded1[i][1] == 0) i++;
            encoded2[j][1] -= mn;
            if(encoded2[j][1] == 0) j++;
            pre = p;
        }
        
        return ans;
    }
};