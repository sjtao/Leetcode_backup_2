class Solution {
public:
    int convert(string s){
        int num = 0;
        int sign = 1;
        if(s[0] == '-') sign = -1;
        int i = sign == 1 ? 0 : 1;
        for(; i < s.length(); i++){
            num = num * 10 + (s[i] - '0');
        }
        return sign * num;
    }
    
    int evalRPN(vector<string>& token) {
        stack<int> st;
        int n = token.size();
        for(int i = 0; i < n; i++){
            if (token[i] == "+" || token[i] == "-" || token[i] == "*" || token[i] == "/"){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                int c;
                if(token[i] == "+")
                    c = a + b;
                else if(token[i] == "-")
                    c = b - a;
                else if(token[i] == "*")
                    c = a * b;
                else if(token[i] == "/")
                    c = b / a;
                st.push(c);
            }
            else{
                st.push(convert(token[i]));
            }
        }
        return st.top();
    }
};