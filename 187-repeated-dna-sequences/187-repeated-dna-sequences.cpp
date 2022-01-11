class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        vector<string> ans;
        
        if(n < 10) return ans;
        unordered_map<string, int> mp;
        string t = "";
        for(int i = 0; i <= n-10; i++){
            t = "";
            for(int j = i; j < i+10; j++){
                t += s[j];
            }
            mp[t]++;
        }
        
        for(auto it : mp){
            if(it.second > 1){
                ans.push_back(it.first);
            }
        }
        
        return ans;
    }
};