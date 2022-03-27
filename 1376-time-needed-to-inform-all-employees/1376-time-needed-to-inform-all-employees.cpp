class Solution {
public:
    unordered_map<int, vector<int>> mp; //manager: <subordinates>
    vector<int> Time, news;
    
    void findtime(vector<int>& m, int t){
        for(int n : m){
            if(mp.find(n) != mp.end()){
                findtime(mp[n], t + Time[n]);
            }
            else{
                news.push_back(t);
            }
        }
        return;
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        if(n == 1) return informTime[0];
        if(n == 2) return informTime[headID];
        
        Time = vector<int>(informTime.begin(), informTime.end());
        
        for(int i = 0; i < n; i++)
            mp[manager[i]].push_back(i);
        
        findtime(mp[headID], informTime[headID]);
        sort(news.begin(), news.end());
        
        return news.back();
        
    }
};