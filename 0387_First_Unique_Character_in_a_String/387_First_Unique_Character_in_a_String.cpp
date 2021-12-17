//Runtime: 24 ms, faster than 86.71% of C++ online submissions for First Unique Character in a String.
//Memory Usage: 10.6 MB, less than 68.97% of C++ online submissions for First Unique Character in a String.

class Solution {
public:
    int firstUniqChar(string s) {
        
        if(s.length() == 1) return 0;
        
        vector<int> repeat(26, 0);
        
        for(int i = 0; i < s.length(); i++){
            repeat[s[i]-'a'] += 1;
        }
        
        for(int i = 0; i < s.length(); i++){
            if(repeat[s[i]-'a'] == 1){
                return i;
            }
        }
        
        return -1;
    }
};

/**
Runtime: 62 ms, faster than 17.44% of C++ online submissions for First Unique Character in a String.
Memory Usage: 10.8 MB, less than 14.33% of C++ online submissions for First Unique Character in a String.
*/
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;
        for(char c : s){
            mp[c]++;
        }
        for(int i = 0; i < s.length(); i++){
            if(mp[s[i]] == 1){
                return i;
            }
        }
        
        return -1;
    }
};
