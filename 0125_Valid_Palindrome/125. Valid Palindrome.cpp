//Runtime: 8 ms, faster than 54.11% of C++ online submissions for Valid Palindrome.
//Memory Usage: 7.7 MB, less than 17.55% of C++ online submissions for Valid Palindrome.

class Solution {
public:
    string cleanstring(string s){
        string cs;
        int i = 0;
        while(i < s.length()){
            if(s[i] -'a' >= 0 && s[i] - 'z' <= 0){
                cs.push_back(s[i]);
            }
            else if( s[i] -'A' >= 0 && s[i] - 'Z' <= 0){
                cs.push_back(s[i] - 'A' + 'a');
            }
            else if( s[i] -'0' >= 0 && s[i] - '9' <= 0){
                cs.push_back(s[i]);
            }
            i++;
        }
        return cs;
    }
    
    bool isPalindrome(string s) {
        string cs = cleanstring(s);
        int i =0, j = cs.length()-1;
        while(i < j){
            if(cs[i] == cs[j]){
                i++;
                j--;
            }
            else{
                return 0;
            }
        }
        return 1;
    }
};
