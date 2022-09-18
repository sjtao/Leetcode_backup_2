class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char, int> mp;
        int len = 0;
        for(int i = 0, j = 0; i < n; i++){
            if(mp[s[i]] > 0){
                j = max(mp[s[i]], j);
            }
            mp[s[i]] = i+1;
            len = max(len, i-j+1);
        }
        return len;
    }
};