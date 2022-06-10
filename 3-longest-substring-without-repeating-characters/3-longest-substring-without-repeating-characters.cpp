class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int n = s.length();
        int len = 0;
        for(int i = 0, j = 0; j < n; j++){
            if(mp.find(s[j]) != mp.end()){
                i = max(i, mp[s[j]]);
            }
            len = max(len, j - i + 1);
            mp[s[j]] = j + 1;
        }
        return len;
    }
};