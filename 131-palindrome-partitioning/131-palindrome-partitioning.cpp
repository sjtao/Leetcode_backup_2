class Solution {
public:
    int n;
    bool ispalindrome(string& s, int low, int high){
        while(low < high){
            if(s[low++] != s[high--])
                return false;
        }
        return true;
    }
    
    void dfs(vector<vector<string>>& ans, string& s, int idx, vector<string>& st){
        if(idx == n){
            ans.push_back(st);
            return;
        }
        
        for(int i = idx; i < n; ++i){
            if(ispalindrome(s, idx, i)){
                st.push_back(s.substr(idx, i-idx+1));
                dfs(ans, s, i+1, st);
                st.pop_back();
            } 
        }
        
        return;
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        n = s.length();
        vector<string> st;
        dfs(ans, s, 0, st);
        return ans;
    }
};