class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.length();
        if(n <= 1) return false;
        
        st.push(s[0]);
        int i = 1;
        while(i < n){
            if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
                if(st.size() == 0) return false;
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