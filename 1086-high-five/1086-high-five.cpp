class Solution {
public:   
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        unordered_map<int, priority_queue<int>> mp;
        for(auto i : items){
            mp[i[0]].push(i[1]);
        }
        
        vector<vector<int>> ans;
        
        for(auto& it : mp){
            int sum = 0;
            for(int k = 0; k < 5; ++k){
                sum += it.second.top();
                it.second.pop();
            }
            ans.push_back({it.first, sum/5});
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};