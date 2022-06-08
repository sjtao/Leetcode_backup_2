class Solution {
public:
    int removePalindromeSub(string s) {
        int n = s.length();
        if(n < 2)
            return n;
        
        for(int i = 0; i < n; ++i){
            if(s[n-1-i] != s[i])
                return 2;
        }
        
        return 1;
    }
};