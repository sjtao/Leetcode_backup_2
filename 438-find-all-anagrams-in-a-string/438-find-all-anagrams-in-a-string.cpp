class Solution {
public:
    bool compare(vector<int>& va, vector<int>& vb){
        for(int i = 0; i < 26; i++){
            if(va[i] != vb[i])
                return false;
        }
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int ns = s.length();
        int np = p.length();
        if(ns < np) return ans;
        
        vector<int> vs(26, 0), vp(26,0);
        for(char c : p)
            vp[c-'a']++;
        
        for(int i = 0; i < ns; i++){
            vs[s[i] - 'a']++;
            if(i >= np)
                vs[s[i-np] - 'a']--;
            if(compare(vs, vp))
                ans.push_back(i-np+1);
        }
        
        return ans;
    }
};