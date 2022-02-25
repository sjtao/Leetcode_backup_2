class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp; //char, index
        int n = s.length();
        if(n <= 1) return n;
        int start = 0;
        int longest = 0;
        int cur = 0;
        for(int i = 0; i < n; ++i){
            if(mp.find(s[i]) != mp.end()){
                start = mp[s[i]] < start ? start : mp[s[i]]+1;
            }
            cur = i - start + 1;
            mp[s[i]] = i;
            longest = max(longest, cur);
        }
        return longest;
    }
};