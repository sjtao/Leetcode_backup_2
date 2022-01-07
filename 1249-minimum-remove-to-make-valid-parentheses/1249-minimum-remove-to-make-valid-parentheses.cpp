class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        stack<int> st;
        vector<int> rm;
        for(int i = 0; i < n; i++){
            if(s[i] == '(')
                st.push(i);
            if(s[i] == ')'){
                if(st.empty())
                    rm.push_back(i);
                else
                    st.pop();
            }
        }
        
        while(!st.empty()){
            rm.push_back(st.top());
            st.pop();
        }
        
        string a = "";
        for(int i = 0; i < n; i++){
            if(find(rm.begin(), rm.end(), i) == rm.end())
                a += s[i];
        }
        
        return a;
    }
};