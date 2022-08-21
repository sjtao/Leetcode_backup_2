class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        int n = s.length();
        for(int i = 0; i < n; i++){
            if(s[i] == ']'){
                string ds = "";
                while(st.top() != '['){
                    ds = st.top() + ds;
                    st.pop();
                }
                st.pop(); //'['
                int k = 0;
                int base = 1;
                while(!st.empty() && isdigit(st.top())){
                    k = k + (st.top() - '0') * base;
                    st.pop();
                    base *= 10;
                }

                while(k > 0){
                    for(int j = 0; j < ds.size(); j++)
                        st.push(ds[j]);
                    k--;
                }
            }
            else
                st.push(s[i]);
        }
        
        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        
        return ans;
    }
};