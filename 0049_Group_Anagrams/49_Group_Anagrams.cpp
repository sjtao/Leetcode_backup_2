/**
Runtime: 32 ms, faster than 76.95% of C++ online submissions for Group Anagrams.
Memory Usage: 20.4 MB, less than 60.71% of C++ online submissions for Group Anagrams.
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string s:strs){
            string t = s;
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }
        
        vector<vector<string>> ans;
        for(auto p:mp){
            ans.push_back(p.second);
        }
        
        return ans;
    }
};
