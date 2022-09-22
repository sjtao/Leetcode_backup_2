class Solution {
public:
    string reverseWords(string s) {
        if(s.length() == 1) return s;
        
        string res = "";
        string t = "";
        for(char c : s){
            if(isspace(c)){
                reverse(t.begin(), t.end());
                res += t;
                res += c;
                t = "";
            }
            else
                t += c;
        }
        reverse(t.begin(), t.end());
        res += t;
        return res;
    }
};