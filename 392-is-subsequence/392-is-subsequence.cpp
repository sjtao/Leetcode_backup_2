class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ns = s.length();
        int nt = t.length();
        if(ns > nt) return false;
        
        int i = 0, j = 0;
        while(i < ns && j < nt){
            if(s[i] == t[j])
                i++;
            j++;     
        }
        
        return i == ns;
    }
};