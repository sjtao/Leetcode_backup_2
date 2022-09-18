class Solution {
public:
    vector<string> res;
    
    void parenthesis(string& p, int left, int right, int n){
        if(p.length() == 2*n){
            res.push_back(p);
            return;
        }
        
        if(left < n){
            p = p + "(";
            parenthesis(p, left+1, right, n);
            p.pop_back();
        }
        
        if(right < left){
            p = p + ")";
            parenthesis(p, left, right+1, n);
            p.pop_back();
        }
        
        return;
    }
    
    vector<string> generateParenthesis(int n) {
        
        string p = "";
        parenthesis(p, 0, 0, n);
        return res;
        
    }
};