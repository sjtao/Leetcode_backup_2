class Solution {

public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(char c : s)
            mp[c]++;
        
        priority_queue<pair<int, char>> q;
        for(auto& i : mp)
            q.push({i.second, i.first});
        
        string res = "";
        while(!q.empty()){
            auto p = q.top();
            q.pop();
            int a = p.first;
            char c = p.second;
            while(a>0){
                res += c;
                a--;
            }
        }
        
        return res;
    }
};