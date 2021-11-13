//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Word Pattern.
//Memory Usage: 6.4 MB, less than 53.00% of C++ online submissions for Word Pattern.

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        vector<string> s_word;
        
        string str = "";
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' '){
                s_word.push_back(str);
                str = "";
            }
            else{
                str += s[i];
            }
        }
        s_word.push_back(str); //push the last piece of s
        
        if(pattern.length() != s_word.size())
            return false;
        
        unordered_map<char, string> patternToString;
        unordered_map<string, char> stringToPattern;
        
        for(int i = 0; i < pattern.length(); i++){
            char p = pattern[i];
            string sub = s_word[i];
            if (patternToString.count(p) == 0 && stringToPattern.count(sub) == 0) {
                //both p and sub are not shown before
                patternToString[p] = sub;
                stringToPattern[sub] = p;
            } else {
                //shown before, but not correspondingly related
                if (sub != patternToString[p] || p != stringToPattern[sub])
                    return false;
            }
            
        }
        
        return true;
    }
};
