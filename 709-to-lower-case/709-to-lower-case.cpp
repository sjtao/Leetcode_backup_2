class Solution {
public:
    string toLowerCase(string s) {
        //s: printable ASCII character
        for(int i = 0; i < s.length(); ++i){
            int d = s[i] - 'A';
            if(d >= 0 && d < 26)
                s[i] = tolower(s[i]);
        }
        
        return s;
    }
};