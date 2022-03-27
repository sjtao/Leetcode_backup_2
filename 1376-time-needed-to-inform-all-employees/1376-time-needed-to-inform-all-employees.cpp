class Solution {
public:
    unordered_map<int, vector<int>> mp; //manager: <subordinates>
    int ans = -1;
    
    void findtime(vector<int>& m, int t, vector<int>& informTime){
        for(int n : m){
            if(mp.find(n) != mp.end()){
                findtime(mp[n], t + informTime[n], informTime);
            }
            else{
                ans = max(ans, t);
            }
        }
        return;
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        if(n == 1) return informTime[0];
        if(n == 2) return informTime[headID];
        
        for(int i = 0; i < n; i++)
            mp[manager[i]].push_back(i);
        
        findtime(mp[headID], informTime[headID], informTime);
        
        return ans;
    }
};