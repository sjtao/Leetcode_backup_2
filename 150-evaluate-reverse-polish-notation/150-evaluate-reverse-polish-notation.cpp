class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<long> st;
        for(int i = 0; i < n; i++){
            string t = tokens[i];
            if(t == "+" || t == "-" || t == "*" || t == "/"){
                long a = st.top(); st.pop();
                long b = st.top(); st.pop();
                if(t == "+") st.push(a + b);
                else if(t == "-") st.push(b - a);
                else if(t == "*") st.push(a * b);
                else if(t == "/") st.push(b / a);
            }
            else{
                //number
                long a = 0;
                int sign = 1;
                int j = 0;
                if(!isdigit(t[j])){
                    if(t[j] == '-') sign = -1;
                    j++;
                }
                
                for(; j < t.length(); j++){
                    a = a * 10 + (t[j] - '0');
                }
                
                st.push(a * sign);
            }
        }
        
        return st.top();
    }
};