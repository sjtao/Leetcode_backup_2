class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        if(k <= 1) return n;
        if(k > n) return 0;
        
        unordered_map<char, int> mp;
        for(char c : s)
            mp[c]++;
        
        int cur = 0, left = 0, right = 0;
        while(cur < n && mp[s[cur]] >= k) cur++;
        if (cur == n) return n;
        
        left = longestSubstring(s.substr(0, cur), k);
        
        while(cur < n && mp[s[cur]] < k) cur++;
        right = longestSubstring(s.substr(cur), k);
        
        return max(left, right);
    }
};