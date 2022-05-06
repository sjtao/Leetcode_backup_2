class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> mp;
        vector<string> ans;
        int n = s.length();
        if(n < 10)
            return ans;
        
        for(int i = 0; i <= n-10; i++){
            string a = s.substr(i, 10);
            mp[a]++;
        }
        
        for(auto m : mp){
            if(m.second > 1)
                ans.push_back(m.first);
        }
        
        return ans;
    }
};