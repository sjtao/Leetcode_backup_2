class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        if(n==0) return 0;
        
        stack<int> sk;
        int cur = 0;
        char operation = '+';
        
        for(int i = 0; i < n; ++i){
            char c = s[i];
            if(isdigit(c))
                cur = cur * 10 + (c - '0'); //multiple digits
            if(!isdigit(c) && !iswspace(c) || i == n-1){
                if(operation == '+')
                    sk.push(cur);
                else if(operation == '-')
                    sk.push(-cur);
                else if(operation == '*'){
                    int st = sk.top(); sk.pop();
                    sk.push(st * cur);
                }
                else if(operation == '/'){
                    int st = sk.top(); sk.pop();
                    sk.push(st / cur);
                }
                operation = c;
                cur = 0;                
            }
        }
        
        int result = 0;
        while(!sk.empty()){
            result += sk.top();
            sk.pop();
        }
        return result;
    }
};