class Solution {
public:
    bool match(string s, string w){
        int i = 0, j = 0;
        while(i < s.length() && j < w.length()){
            if(s[i] == w[j]){
                i++;
                j++;
            }
            else
                i++;
        }
        
        return j == w.length();
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        int num = 0;
        unordered_map<string, int> mp;
        for(string w : words)
            mp[w]++;
        
        for(auto it : mp){
            if(match(s, it.first))
                num += it.second;
        }
        
        return num;
    }
};