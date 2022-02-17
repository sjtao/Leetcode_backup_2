class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        
        vector<int> v(26, 0);
        for(char c : s)
            v[c-'a']++;
        for(char c : t)
            v[c-'a']--;
        for(int i = 0; i < 26; i++){
            if(v[i] != 0)
                return false;
        }
        return true;
    }
};