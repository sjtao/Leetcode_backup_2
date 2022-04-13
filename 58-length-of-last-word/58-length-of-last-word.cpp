class Solution {
public:
    int lengthOfLastWord(string s) {
        int l = 0, lo = 0;
        for(int i = s.length()-1; i >= 0; i--){
            if(s[i] == ' '){
                if(l > 0)
                    return l;
            }
            else
                l++;
        }
        
        return l;
    }
};