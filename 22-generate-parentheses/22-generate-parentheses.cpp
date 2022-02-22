class Solution {
public:
    pair<int, char> para[2] = {{1, '('}, {-1, ')'}};

    void helper(vector<string>& ans, string s, int left, int right){
        if(left == 0 && right == 0){
            ans.push_back(s);
            return;
        }
        
        if(left > 0)
            helper(ans, s+"(", left-1, right);
        
        if(right > left)
            helper(ans, s+")", left, right-1);
        
        return;
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        helper(ans, s, n, n);
        return ans;
    }
};