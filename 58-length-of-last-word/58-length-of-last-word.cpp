class Solution {
public:
    int lengthOfLastWord(string s) {
        int l = 0, lo = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' '){
                if(l != 0) lo = l;
                l = 0;
            }
            else
                l++;
        }
        return l == 0 ? lo : l;
    }
};