class Solution {
public:
    unordered_map<int, vector<string>> mp = {{2, {"a","b","c"}}, {3, {"d","e","f"}}, {4, {"g","h","i"}}, 
                                           {5, {"j","k","l"}}, {6, {"m","n","o"}}, {7, {"p","q","r","s"}}, 
                                           {8, {"t","u","v"}}, {9, {"w","x","y","z"}}};
    int n;
    void dfs(string digits, int idx, vector<string>& ans, string& t){
        if(idx == n){
            ans.push_back(t);
            return;
        }
        
        int d = digits[idx] - '0';
        for(int i = 0; i < mp[d].size(); i++){
            t += mp[d][i];
            dfs(digits, idx+1, ans, t);
            t.erase(idx, 1);
        }
        
        return;
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        n = digits.length();
        if(n == 0) return ans;
        if(n == 1) return mp[digits[0]-'0'];
        
        string t = ""; 
        dfs(digits, 0, ans, t);
        
        return ans;
    }
};