/**
Runtime: 27 ms, faster than 37.49% of C++ online submissions for Longest Substring Without Repeating Characters.
Memory Usage: 8.6 MB, less than 41.96% of C++ online submissions for Longest Substring Without Repeating Characters.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        map<char, int> charMap;
        int start = -1;
        int maxLen = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (charMap.count(s[i]) != 0) {
                start = max(start, charMap[s[i]]);
            }
            charMap[s[i]] = i;
            maxLen = max(maxLen, i-start);
        }
        
        return maxLen;
    }
};

/**
Runtime: 28 ms
Memory Usage: 8.4 MB
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n < 2) return n; 
        unordered_map<char, int> mp; //index of char
        
        int ans = -1;
        for(int j = 0, i = 0; j < n; j++){
            if(mp.find(s[j]) != mp.end()){
                i = max(mp[s[j]], i);
            }
            ans = max(ans, j-i+1);
            mp[s[j]] = j+1;
        }
        return ans;
    }
};
