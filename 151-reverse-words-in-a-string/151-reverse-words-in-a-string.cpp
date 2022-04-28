class Solution {
public:
    string reverseWords(string s) {
       stack<string> st;
        int len = s.length();
        string a = "";
        for(int i = 0; i < len; i++){
            if(!iswspace(s[i])){
                a += s[i];
            }else{
                if(a.length() > 0){
                    st.push(a);
                    a = "";
                }
            }
        }
        if(a.length() > 0) st.push(a);
        
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
            if(!st.empty())
                ans += " ";
        }
        return ans;
    }
};