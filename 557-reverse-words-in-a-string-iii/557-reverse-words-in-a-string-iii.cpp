class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i = 0, j = 0;
        auto ad = s.begin();
        for(; i < n; i++){
            if(s[i] == ' '){
                reverse(ad+j, ad+i);
                j = i+1;
            }
        }
        reverse(ad+j, s.end());
        return s;
    }
};