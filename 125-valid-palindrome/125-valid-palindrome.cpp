class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int l = 0, r = n-1;
        while(l < r){
            while(l < r && !isalnum(s[l])) l++;
            while(l < r && !isalnum(s[r])) r--;
            if(isupper(s[l])) s[l] = tolower(s[l]);
            if(isupper(s[r])) s[r] = tolower(s[r]);
            if(s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};