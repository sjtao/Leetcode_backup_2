class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> in(n+1, 0);
        vector<int> out(n+1, 0);
        //judge: in = n-1, out = 0
        for(int i=0; i < trust.size(); i++){
            out[trust[i][0]]++;
            in[trust[i][1]]++;
        }
        
        for(int ans = 1; ans <= n; ans++){
            if(in[ans] == n-1 && out[ans] == 0)
                return ans;
        }
        return -1;
    }
};