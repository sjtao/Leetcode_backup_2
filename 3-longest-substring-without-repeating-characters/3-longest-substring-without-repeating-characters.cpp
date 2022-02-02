class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int n = s.length();
        if(n <= 1) return n;
        
        int st = -1;
        int len = INT_MIN;
        for(int i = 0; i < n; i++){
            if(mp.count(s[i]) != 0)
                st = max(st, mp[s[i]]);
            mp[s[i]] = i;
            len = max(len, i - st);
        }
        return len;
    }
};