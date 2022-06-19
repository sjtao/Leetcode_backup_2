class Solution {
public:
    unordered_map<int,int> mp;
    int helper(string s, int d){
        if(mp.find(d) != mp.end())
            return mp[d];
        
        if(d == s.length())
            return 1;
        if(s[d] == '0')
            return 0;
        if(d == s.length()-1)
            return 1;
        
        int ans = helper(s, d+1);
        if(stoi(s.substr(d, 2)) <= 26)
            ans += helper(s, d+2);
        
        mp[d] = ans;
        return ans;
    }
    
    int numDecodings(string s) {
        return helper(s, 0);
    }
};