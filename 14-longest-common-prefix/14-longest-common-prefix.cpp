class Solution {
public:
    void compare(string &ans, string s){
        int a = ans.length();
        int b = s.length();
        string c = "";
        for(int i = 0; i < min(a, b); ++i){
            if(ans[i] != s[i])
                break;
            c += ans[i];
        }
        ans = c;
        return;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ans = strs[0];
        
        for(int i = 1; i < n; i++){
            compare(ans, strs[i]);
            if(ans == "")
                break;
        }
        return ans;
        
    }
};