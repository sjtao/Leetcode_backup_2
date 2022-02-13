class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.length();  
        st.push(s[0]);
        int i = 1;
        while(i < n){
            if(st.size() > 0){
                char t = st.top();
                if((s[i] == ')' && t == '(') ||
                   (s[i] == '}' && t == '{') ||
                   (s[i] == ']' && t == '['))
                    st.pop();
                else
                    st.push(s[i]);
            }
            else{
                st.push(s[i]);
            }
            i++;
        }
        return st.size() == 0;
    }
};