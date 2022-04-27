class Solution {
public:
    int calculate(string s) {
        int len = s.length();
        if(len == 0) return 0;
        stack<int> st;
        int cur = 0, last = 0, result = 0;
        char operation = '+';
        for(int i = 0; i < len; i++){
            char c = s[i];
            if(isdigit(c)){
                cur = 10 * cur + (c - '0');
            }
            if(!isdigit(c) && !iswspace(c) || i == len-1){
                if(operation == '+' || operation == '-'){
                    result += last;
                    last = (operation == '-') ? -cur : cur;
                }
                else if(operation == '*'){
                    last *= cur;
                }
                else if(operation == '/'){
                    last /= cur;
                }
                operation = c;
                cur = 0;
            }
        }

        return result + last;
    }
};