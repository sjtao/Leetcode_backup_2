class Solution {
public:
    string remove(string s, char open, char close){
        int p = 0;
        string a = "";
        for(char c : s){
            if(c == open){
                p++;
            }
            else if(c == close){
                p--;
                if(p < 0){
                    p = 0;
                    continue;
                }
            }
            a += c;
        }
        
        return a;
    }
    
    string minRemoveToMakeValid(string s) {
        string a = remove(s, '(', ')');
        reverse(a.begin(), a.end());
        string b = remove(a, ')', '(');
        reverse(b.begin(), b.end());
        return b;
    }
};