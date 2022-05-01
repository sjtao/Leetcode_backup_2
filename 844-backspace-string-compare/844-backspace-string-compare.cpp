class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> sstack, tstack;
        for(char c : s){
            if(c == '#'){
                if(!sstack.empty())
                    sstack.pop();
            }
            else
                sstack.push(c);
        }
        
        for(char c : t){
            if(c == '#'){
                if(!tstack.empty())
                    tstack.pop();
            }
            else
                tstack.push(c);
        }
        
        if(sstack.size() != tstack.size())
            return false;
        
        while(!sstack.empty() && !tstack.empty()){
            if(sstack.top() != tstack.top())
                return false;
            sstack.pop();
            tstack.pop();
        }
        
        return true;
    }
};