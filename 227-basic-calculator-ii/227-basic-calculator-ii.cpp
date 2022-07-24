class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int n = s.length();
        int i = 0;
        char sign;
        while(i < n){
            if(isdigit(s[i])){
                int a = 0;
                while(isdigit(s[i])){
                    a = a * 10 + (s[i++] - '0');
                }
                if(st.empty())
                    st.push(a);
                else{
                    if(sign == '+')
                        st.push(a);
                    else if(sign == '-')
                        st.push(-a);
                    else if(sign == '*'){
                        int b = st.top();
                        st.pop();
                        st.push(a * b);
                    } 
                    else if(sign == '/'){
                        int b = st.top();
                        st.pop();
                        st.push(b / a);
                    }
                }
            }
            else if(isspace(s[i])){
                while(isspace(s[i]))
                    i++;
            }
            else{
                sign = s[i++];
            }
        }
        
        int ans = 0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        return ans;
    }
};