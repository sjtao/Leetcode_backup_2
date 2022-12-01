class Solution {
public:
    bool isVowel(char &c){        
        return c == 'a' || c == 'e' || c =='i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';        
    }
    bool halvesAreAlike(string s) {
        int n = s.length() / 2;
        int first = 0;
        for(int i = 0; i < n; i++){
            if(isVowel(s[i]))
                first++;
            if(isVowel(s[i+n]))
                first--;
        }
        return first == 0;
    }
};