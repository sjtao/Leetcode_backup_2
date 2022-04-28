class Solution {
public:
    string reverseWords(string s) {
       vector<string> st;
        int len = s.length();
        string a = "";
        for(int i = 0; i < len; i++){
            if(!iswspace(s[i])){
                a += s[i];
            }else{
                if(a.length() > 0){
                    st.push_back(a);
                    a = "";
                }
            }
        }
        if(a.length() > 0) st.push_back(a);
        reverse(st.begin(), st.end());
        
        string ans = "";
        for(int i = 0; i < st.size(); i++){
            ans += st[i];
            if(i != st.size()-1)
                ans += " ";
        }
        return ans;
    }
};