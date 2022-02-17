class Solution {
public:
    bool isPalindrome(string s) {
        string f = "";
        for(char c : s){
            if(isalnum(c))
                f += tolower(c);
        }
        
        string r = f;
        reverse(f.begin(), f.end());
        return f == r;
    }
};