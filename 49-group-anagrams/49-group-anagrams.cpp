class Solution {
public:
    /*
    int hashnum = 100;
    int hashing(string s){
        int num = 0;
        for(char c : s){
            num += (c - 'a' + 1) % hashnum;
            num %= hashnum;
        }
        return num;
    }
    */
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
 
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
        
        for(string& s : strs){
            string t = s;
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }
        
        for(auto& it:mp){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};