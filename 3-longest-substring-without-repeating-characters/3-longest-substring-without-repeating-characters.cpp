class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int n = s.length();
        int i = 0, j = 0;
        int res = 0;
        
        while(j < n){
            mp[s[j]]++;
            while(mp[s[j]] > 1){
                mp[s[i]]--;
                i++;
            }
            res = max(res, j-i+1);
            j++;
        }
        
        return res;
    }
};