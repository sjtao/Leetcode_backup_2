class Solution {
public:
    int calculate(string s) {
        int len = s.length();
        if(len == 0) return 0;
        stack<int> st;
        int cur = 0;
        char operation = '+';
        for(int i = 0; i < len; i++){
            char c = s[i];
            if(isdigit(c)){
                cur = 10 * cur + (c - '0');
            }
            if(!isdigit(c) && !iswspace(c) || i == len-1){
                if(operation == '+')
                    st.push(cur);
                else if(operation == '-')
                    st.push(-cur);
                else if(operation == '*'){
                    int a = st.top();
                    st.pop();
                    st.push(a * cur);
                }
                else if(operation == '/'){
                    int a = st.top();
                    st.pop();
                    st.push(a / cur);
                }
                operation = c;
                cur = 0;
            }
        }
        
        int result = 0;
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        
        return result;
    }
};