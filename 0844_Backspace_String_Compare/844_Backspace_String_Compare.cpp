/**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Backspace String Compare.
Memory Usage: 6.2 MB, less than 66.17% of C++ online submissions for Backspace String Compare.
*/

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.length()-1;
        int j = t.length()-1;
        int bs = 0, bt = 0;
        while(i >= 0 || j >= 0){
            while(i >= 0){
                if(s[i] == '#'){
                    bs ++; i--;
                }
                else if(bs > 0){
                    bs--; i--;
                }
                else
                    break;
            }
            while(j >= 0){
                if(t[j] == '#'){
                    bt ++; j--;
                }
                else if(bt > 0){
                    bt--; j--;
                }
                else
                    break;
            }
            if(i>=0 && j>=0 && s[i]!=t[j]) return false;
            if(i>=0 != j>=0) return false;
            i--; j--;
        }
        return true;
    }
};
