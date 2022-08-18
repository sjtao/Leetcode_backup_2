class Solution {
public:
    int n;
    int expand(string s, int l, int r){
        if(l > r) return 0;
        while(l >= 0 && r < n && s[l] == s[r]){
            l--;
            r++;
        }
        return r-l-1;
    }
    
    string longestPalindrome(string s) {
        n = s.length();
        if(n == 1) return s;
        
        int m = 0;
        int start = 0;
        for(int i = 0; i < n; i++){
            int len1 = expand(s, i, i);
            int len2 = expand(s, i, i+1);
            int len = max(len1, len2);
            if(len > m){
                m = len;
                start = i - (len - 1) / 2;
            }
        }
        
        return s.substr(start, m);
    }
};