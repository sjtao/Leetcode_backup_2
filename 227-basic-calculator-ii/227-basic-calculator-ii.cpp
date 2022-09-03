class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        stack<int> st;
        int i = 0;
        char sign = '+'; //plus, minus, multiply, divide
        while(i < n){
            if(isspace(s[i])){
                while(isspace(s[i]))
                    i++;
            }
            
            else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
                sign = s[i++];
            
            else if(isdigit(s[i])){
                int num = 0;
                while(isdigit(s[i])){
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                if(st.empty() || sign == '+')
                    st.push(num);
                else if(sign == '-')
                    st.push(-num);
                else if(sign == '*'){
                    num = st.top() * num;
                    st.pop();
                    st.push(num);
                }
                else if(sign == '/'){
                    num = st.top() / num;
                    st.pop();
                    st.push(num);
                }  
            }
        }
        
        int res = 0;
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        return res;
    }
};