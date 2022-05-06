class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.length();
        stack<int> st;
        
        for(int i = 0; i < n; i++){
            if(i == 0 || s[i] != s[i-1])
                st.push(1);
            else{
                st.top()++;
                if(st.top() == k){
                    st.pop();
                    s.erase(i-k+1, k);
                    i = i-k;
                }
            }
        }
        
        return s;
    }
};