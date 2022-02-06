class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> mp;
    vector<string> ans;
    
    void dfs_helper(string city){
        auto & from = mp[city];
        while(!from.empty()){
            string to = from.top();
            from.pop();
            dfs_helper(to);
        }
        ans.push_back(city);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();
        int city = n+1;
        //Goal:
        //the itinerary must begin with "JFK"
        //smallest lexical order when read as a single string
        for(auto s: tickets){
            mp[s[0]].push(s[1]);
        }
        
        dfs_helper("JFK");
        reverse(ans.begin(), ans.end());
        
        return ans;
        
    }
};