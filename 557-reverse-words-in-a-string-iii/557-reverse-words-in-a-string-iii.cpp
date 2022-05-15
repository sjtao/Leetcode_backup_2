class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i = 0, j = 0;
        for(; i < n; i++){
            if(s[i] == ' '){
                reverse(s.begin()+j, s.begin()+i);
                j = i+1;
            }
        }
        reverse(s.begin()+j, s.begin()+n);
        return s;
    }
};