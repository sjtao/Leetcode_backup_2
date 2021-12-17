/**
Runtime: 37 ms, faster than 5.47% of C++ online submissions for Valid Anagram.
Memory Usage: 7.3 MB, less than 43.25% of C++ online submissions for Valid Anagram.
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        //An anagram is produced by rearranging the letters of s into t
        if(s.length() != t.length()) return false;
        
        unordered_map<char, int> sp;
        for(char c: s){
            sp[c]++;
        }
        for(char c:t){
            if(sp.find(c) == sp.end()) // t has c but s doesn't
                return false;
            else if(sp[c] <= 0) //t has more c than s
                return false;
            else
                sp[c]--;
        }
        return true;
    }
};

/**
Runtime: 24 ms, faster than 5.47% of C++ online submissions for Valid Anagram.
Memory Usage: 7.4 MB, less than 43.25% of C++ online submissions for Valid Anagram.
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        //An anagram is produced by rearranging the letters of s into t
        if(s.length() != t.length()) return false;
        
        unordered_map<char, int> sp, tp;
        for(char c: s){
            sp[c]++;
        }
        for(char c:t){
            tp[c]++;
        }
        for(char c:s){
            if(tp.find(c) == tp.end() || tp[c] != sp[c])
                return false;
        }
        return true;
    }
};

/**
Runtime: 18 ms, faster than 11.29% of C++ online submissions for Valid Anagram.
Memory Usage: 7.4 MB, less than 7.18% of C++ online submissions for Valid Anagram.
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        //An anagram is produced by rearranging the letters of s into t
        if(s.length() != t.length()) return false;
        
        unordered_map<char, int> sp;
        int n = s.length();
        for(int i = 0; i < n; i++){
            sp[s[i]]++;
            sp[t[i]]--;
        }
        
        for(auto c : sp){
            if(c.second != 0)
                return false;
        }

        return true;
    }
};

/**
Runtime: 11 ms, faster than 53.58% of C++ online submissions for Valid Anagram.
Memory Usage: 7.4 MB, less than 43.25% of C++ online submissions for Valid Anagram.
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        //An anagram is produced by rearranging the letters of s into t
        if(s.length() != t.length()) return false;
        
        vector<int> sp(26, 0);
        int n = s.length();
        for(int i = 0; i < n; i++){
            sp[s[i]-'a']++;
            sp[t[i]-'a']--;
        }
        
        for(auto c : sp){
            if(c != 0)
                return false;
        }

        return true;
    }
};
