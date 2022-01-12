class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> judge(n+1, 0);
        for(int i=0; i < trust.size(); i++){
            judge[trust[i][0]]--;
            judge[trust[i][1]]++;
        }
        
        for(int ans = 1; ans <= n; ans++){
            if(judge[ans] == n-1)
                return ans;
        }
        return -1;
    }
};