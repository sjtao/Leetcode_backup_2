class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int ns = s.length();
        int nt = t.length();
        if(ns != nt) return false;
        
        unordered_map<char, char> sp, tp;
        
        for(int i = 0; i < ns; i++){
            if(sp.find(s[i]) == sp.end() && tp.find(t[i]) == tp.end()){
                sp[s[i]] = t[i];
                tp[t[i]] = s[i];
            }
            else if(!(sp[s[i]] == t[i] && tp[t[i]] == s[i]))
                return false;
        }
        
        return true;
    }
};