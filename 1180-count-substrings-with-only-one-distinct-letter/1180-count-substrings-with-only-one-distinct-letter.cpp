class Solution {
public:
    int countLetters(string s) {
        int uni = 1;
        int ans = 1;
        for(int i = 1; i < s.length(); ++i){
            if(s[i] == s[i-1])
                uni ++;
            else
                uni = 1;
            ans += uni;
        }
        
        return ans;
    }
};