class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.length() != s2.length())
            return false;
        
        int d = 0;
        vector<int> r(26,0);
        for(int i = 0; i < s1.length(); ++i){
            r[s1[i]-'a']++;
            r[s2[i]-'a']--;
            if(s1[i] != s2[i])
                d++;
        }
        
        for(int i = 0; i < 26; ++i){
            if(r[i] != 0)
                return false;
        }
            
        
        if(d == 0 || d == 2)
            return true;
        
        return false;
    }
};