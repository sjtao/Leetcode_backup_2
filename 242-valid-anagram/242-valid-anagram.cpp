class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1 = s.length();
        int n2 = t.length();
        if(n1 != n2) return false;
        
        vector<int> r(26, 0);
        for(int i = 0; i < n1; ++i){
            r[s[i]-'a']++;
            r[t[i]-'a']--;
        }
        
        for(int i = 0; i < 26; ++i){
            if(r[i] != 0)
                return false;
        }
        
        return true;
    }
};