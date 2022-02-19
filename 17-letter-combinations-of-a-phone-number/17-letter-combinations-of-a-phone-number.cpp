class Solution {
public:
    unordered_map<int, string> mp = {{2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, 
                                     {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};
    int n;
    void dfs(string digits, int idx, vector<string>& ans, string& t){
        if(idx == n){
            ans.push_back(t);
            return;
        }
        
        int d = digits[idx] - '0';
        for(int i = 0; i < mp[d].length(); i++){
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

        string t = ""; 
        dfs(digits, 0, ans, t);
        
        return ans;
    }
};