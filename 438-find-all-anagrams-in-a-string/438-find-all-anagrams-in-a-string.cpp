class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ns = s.length();
        int np = p.length();
        if(ns < np) return {};
        
        vector<int> ans;
        vector<int> rs(26, 0);
        vector<int> rp(26, 0);
        for(char c : p)
            rp[c-'a']++;
        
        for(int i = 0; i < np; ++i){
            rs[s[i]-'a']++; 
        }
        if(equal(rp.begin(), rp.end(), rs.begin()))
                ans.push_back(0);
        
        for(int i = np; i < ns; ++i){
            rs[s[i]-'a']++;
            rs[s[i-np]-'a']--;
            if(equal(rp.begin(), rp.end(), rs.begin()))
                ans.push_back(i-np+1);
        }
        return ans;
    }
};