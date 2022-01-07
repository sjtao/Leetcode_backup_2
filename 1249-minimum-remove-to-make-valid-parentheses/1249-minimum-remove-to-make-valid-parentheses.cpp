class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        stack<int> st;
        for(int i = 0; i < n; i++){
            if(s[i] == '(')
                st.push(i);
            if(s[i] == ')'){
                if(st.empty())
                    s[i] = '#';
                else
                    st.pop();
            }
        }
        
        while(!st.empty()){
            s[st.top()] = '#';
            st.pop();
        }
        
        string a = "";
        for(int i = 0; i < n; i++){
            if(s[i] != '#')
                a += s[i];
        }
        
        return a;
    }
};