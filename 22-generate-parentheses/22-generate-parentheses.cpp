class Solution {
public:
    void helper(vector<string>& ans, string& s, int open, int close, int n){
        if(s.length() == 2 * n){
            ans.push_back(s);
            return;
        }
        if(open < n){
            s += "(";
            helper(ans, s, open+1, close, n);
            s.pop_back();
        }
        if(close < open){
            s += ")";
            helper(ans, s, open, close+1, n);
            s.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        helper(ans, s, 0, 0, n);
        return ans;
    }
};