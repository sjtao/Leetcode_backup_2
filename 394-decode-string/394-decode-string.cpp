class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        int n = s.size();
        
        for(int i = 0; i < n; i++){
            string temp;
            if(s[i] != ']'){
                if(s[i] >= '0' && s[i] <= '9'){
                    if(!st.empty() && "0" <= st.top() && st.top() <= "9"){ //multiple-digit number
                        temp = st.top() + s[i];
                        st.pop();
                        st.push(temp);
                    }
                    else
                        st.push(temp + s[i]); //1-digit number
                }
                else
                    st.push(temp + s[i]);             
            }
            else{
                string c;
                while(st.top() != "["){
                    c = st.top(); st.pop();
                    temp = c+temp;
                }
                st.pop(); //pop '['
                c = st.top(); st.pop();
                int r = stoi(c);
                string tp = "";
                while(r){
                    tp += temp; r--;
                }
                st.push(tp);
            }
        }
        
        string ans;
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};