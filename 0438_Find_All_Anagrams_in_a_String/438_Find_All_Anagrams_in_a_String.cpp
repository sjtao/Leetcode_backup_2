//TLE
class Solution {
public:
    unordered_map<char, int> MP;
    bool anagrams(string a){
        unordered_map<char, int> mp = MP;
        
        for(char c : a){
            if(mp.find(c) == mp.end())
                return false;
            else
                mp[c]--;
        }
        
        for(auto it : mp){
            if(it.second != 0)
                return false;
        }
        
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        int ns = s.length();
        int np = p.length();
        
        for(char c:p)
            MP[c]++;
        
        vector<int> ans;
        
        for(int i = 0; i <= ns - np; i++){
            if(anagrams(s.substr(i, np)))
                ans.push_back(i); 
        }
        
        return ans;
    }
};

/**
Runtime: 61 ms, faster than 12.40% of C++ online submissions for Find All Anagrams in a String.
Memory Usage: 11.9 MB, less than 19.27% of C++ online submissions for Find All Anagrams in a String.
*/
//slide windows with 2 hashmaps
class Solution {
public:
    
    vector<int> findAnagrams(string s, string p) {
        int ns = s.length();
        int np = p.length();
        unordered_map<char, int> mp, sp;
        
        for(char c:p)
            mp[c]++;
        
        vector<int> ans;
        
        for(int i = 0; i < ns; i++){
            sp[s[i]]++;
            if(i >= np){
                if(sp[s[i-np]]==1)
                    sp.erase(s[i-np]);
                else
                    sp[s[i-np]]--;
            }
            if(mp == sp) ans.push_back(i-np+1);
            
        }
        
        return ans;
    }
};
