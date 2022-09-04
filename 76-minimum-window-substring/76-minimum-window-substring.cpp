class Solution {
public:
    string minWindow(string s, string t) {
        int ns = s.length();
        int nt = t.length();
        if(ns == 0 || nt == 0 || ns < nt) return "";
        
        unordered_map<char, int> mpt;
        for(char c : t)
            mpt[c]++;
        
        int l = 0;
        int count = 0; //number of char in t has been found
        int minlen = ns + 1;
        int minstart = 0;
        for(int r = 0; r < ns; r++){
            if(mpt[s[r]] > 0) count++;
            mpt[s[r]]--;
            if(count == nt){
                while(l < r && mpt[s[l]] < 0){
                    mpt[s[l]]++;
                    l++;
                }
                if(minlen > r - l + 1){
                    minstart = l;
                    minlen = r - l + 1;
                }
                mpt[s[l]]++;
                l++;
                count--;
            }
        }
        return minlen == ns + 1 ? "" : s.substr(minstart, minlen);
    }
};