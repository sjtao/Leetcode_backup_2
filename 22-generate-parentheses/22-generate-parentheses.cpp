class Solution {
public:
    pair<int, char> para[2] = {{1, '('}, {-1, ')'}};

    void helper(vector<string>& ans, string& s, int left, int n){
        if(s.length() == 2*n){
            if(left == 0)
                ans.push_back(s);
            return;
        }
        
        if(left < 0 || left > n)
            return;
        
        for(int i = 0; i < 2; i++){
            s = s + para[i].second;
            helper(ans, s, left+para[i].first, n);
            s.pop_back();
        }
        
        return;
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "(";
        helper(ans, s, 1, n);
        return ans;
    }
};