//Runtime: 4 ms, faster than 93.79% of C++ online submissions for Isomorphic Strings.
//Memory Usage: 7 MB, less than 41.62% of C++ online submissions for Isomorphic Strings.

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()==1) return true;
        //two strings have the same style: *****+++&&&**
        //number of ascii code: 256(0-255)
        vector<int> smap(256, 0);
        vector<int> tmap(256, 0);
        
        for(int i = 0; i < s.length(); i++){
            if(smap[s[i]] != tmap[t[i]])
                return false;
            smap[s[i]] = i+1; //at the same position
            tmap[t[i]] = i+1;
        }
        
        return true;
    }
};

/**
Runtime: 8 ms, faster than 61.84% of C++ online submissions for Isomorphic Strings.
Memory Usage: 7.2 MB, less than 18.25% of C++ online submissions for Isomorphic Strings.
*/

class Solution {
public:
    bool helper(string s, string t){
                int ns = s.size();
        int nt = t.size();
        if(ns != nt) return false;
        
        unordered_map<char, char> mp;
        for(int i = 0; i < ns; i++){
            if(mp.find(s[i]) == mp.end()){
                mp[s[i]] = t[i];
            }
            else{
                if(t[i] != mp[s[i]])
                    return false;
            }
        }
        
        return true;
    }
    bool isIsomorphic(string s, string t) {
        return helper(s, t) && helper(t, s);
    }
};
