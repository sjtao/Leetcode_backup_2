class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        stack<int> st;
        vector<int> rm(n, 0);
        for(int i = 0; i < n; i++){
            if(s[i] == '(')
                st.push(i);
            if(s[i] == ')'){
                if(st.empty())
                    rm[i] = 1;
                else
                    st.pop();
            }
        }
        
        while(!st.empty()){
            rm[st.top()] = 1;
            st.pop();
        }
        
        string a = "";
        for(int i = 0; i < n; i++){
            if(rm[i] == 0)
                a += s[i];
        }
        
        return a;
    }
};