class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        string t;
        for(string s : strs){
            t = s;
            sort(s.begin(), s.end());
            mp[s].push_back(t);
        }
        
        vector<vector<string>> ans;
        for(auto it : mp)
            ans.push_back(it.second);
        
        return ans;
    }
};