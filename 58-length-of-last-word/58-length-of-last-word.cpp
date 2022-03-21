class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int l = 0, lo;
        for(int i = 0; i < n; ++i){
            if(s[i] == ' '){
                if(l > 0) lo = l;
                l = 0;
            }
            else{
                l++;
            }
        }
        return l == 0 ? lo : l;
    }
};