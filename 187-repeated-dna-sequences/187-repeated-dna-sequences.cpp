class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> mp;
        int n = s.length();
        if(n < 10) return {};
        
        for(int i = 0; i+10 <= n; i++){
            string t = s.substr(i, 10);
            mp[t]++;
        }
        vector<string> rep;
        for(auto it : mp){
            if(it.second > 1)
                rep.push_back(it.first);
        }
        return rep;
    }
};