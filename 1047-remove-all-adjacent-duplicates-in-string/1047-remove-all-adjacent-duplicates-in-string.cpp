class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(char c : s){
            if(st.empty() || c != st.top())
                st.push(c);
            else{
                while(!st.empty() && c == st.top()){
                    st.pop();
                }
            }
        }
        
        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        
        return ans;
    }
};