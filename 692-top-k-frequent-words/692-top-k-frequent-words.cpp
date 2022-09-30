class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(string s : words)
            mp[s]++;
        
        priority_queue<pair<int, string>> p;
        for(auto& i : mp){
            p.push({-i.second, i.first});
            if(p.size() > k)
                p.pop();
        }
        
        vector<pair<int, string>> q;
        while(!p.empty()){
            q.push_back(p.top());
            p.pop();
        }
        sort(q.begin(), q.end());
        
        vector<string> res;
        for(auto& a : q){
            res.push_back(a.second);
        }
        
        return res;
    }
};