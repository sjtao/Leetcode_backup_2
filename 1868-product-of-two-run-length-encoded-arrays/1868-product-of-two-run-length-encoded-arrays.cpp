class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        int n1 = encoded1.size();
        int n2 = encoded2.size();
        
        int i1 = 0, i2 = 0;
        vector<vector<int>> ans;
        while(i1 < n1 && i2 < n2){
            int a = encoded1[i1][0];
            int b = encoded2[i2][0];
            int r = a * b;
            int k = min(encoded1[i1][1], encoded2[i2][1]);
            if(k == encoded1[i1][1]) i1++;
            else encoded1[i1][1] -= k;
            if(k == encoded2[i2][1]) i2++;
            else encoded2[i2][1] -= k;

            if(!ans.empty() && ans.back()[0] == r)
                ans.back()[1] += k;
            else
                ans.push_back({r,k});
        }
        return ans;
    }
};