class Solution {
public:
    bool valid(string s, int i, int j){
        while(i < j){
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int n = s.length();
        if(s.length() <= 2) return true;
        int l = 0, r = n-1;
        while(l < r){
            if(s[l] != s[r])
                return valid(s, l+1, r) || valid(s, l, r-1);
            l++;
            r--;
        }
                                                                        
        return true;
    }
};