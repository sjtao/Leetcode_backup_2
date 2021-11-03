//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Parentheses.
//Memory Usage: 6.1 MB, less than 96.37% of C++ online submissions for Valid Parentheses.

class Solution {
public:
    bool isValid(string s) {
        if(s.length() == 1) return false;
        
        stack<char> paren;

        char q;
        for(char p: s)
        {
            if(paren.empty()){
                paren.push(p);
            }
            else{
                q = paren.top();
                if((q == '(' && p == ')') || (q == '[' && p == ']') || (q == '{' && p == '}'))
                    paren.pop();
                else
                    paren.push(p);
            }          
        }
        
        return paren.empty();
    }
};
