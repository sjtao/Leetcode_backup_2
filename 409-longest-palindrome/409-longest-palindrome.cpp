class Solution {
public:
    
    int longestPalindrome(string s) {
        int len = s.length();
        if(len == 1) return 1;
        
        unordered_map<char, int> mp;
        for(char c : s)
            mp[c] = (mp[c] + 1) % 2;

        int odd = 0;
        for(auto it : mp)
            odd += it.second;
        
        return odd > 0 ? len - odd + 1 : len - odd;
    }
};