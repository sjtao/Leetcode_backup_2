class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        if(n < 2) return n;
        
        unordered_map<char,int> mp;
        for(char c: s)
            mp[c]++;
        
        int odd = 0;
        for(auto m : mp){
            if(m.second % 2)
                odd++;
        }
        
        return odd == 0 ? n : n-odd+1;
    }
};