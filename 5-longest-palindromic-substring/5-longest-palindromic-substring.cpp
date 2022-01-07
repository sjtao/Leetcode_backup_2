class Solution {
public:
    int n;
    int lengthhelper(string s, int l, int r){
        while( l >= 0 && r < n && s[l] == s[r]){
            l--; r++; 
        }
        return r-l-1;
    }
    string longestPalindrome(string s) {
        n = s.length();
        int start = 0, end = 0;
        int l, r, len;
        for(int i = 0; i < n; i++){
            l = lengthhelper(s, i, i);
            r = lengthhelper(s, i, i+1);
            len = max(l, r);
            if(len > end - start){
                start = i - (len-1) / 2;
                end   = i + len / 2;
            }
        }
        return s.substr(start, end-start+1);
    }
};