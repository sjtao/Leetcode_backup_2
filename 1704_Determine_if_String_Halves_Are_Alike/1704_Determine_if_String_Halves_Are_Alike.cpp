//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Determine if String Halves Are Alike.
//Memory Usage: 6.6 MB, less than 50.24% of C++ online submissions for Determine if String Halves Are Alike.

class Solution { 
public:
    bool isVowel(char x){
        if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' ||
          x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U'){
            return true;
        }
        return false;
    }
    
    bool halvesAreAlike(string s) {
        int numleft = 0, numright = 0;
        int l = 0;
        int r = s.length()-1;
        while(l < r){
            if(isVowel(s[l])){
                numleft ++;
            }
            if(isVowel(s[r])){
                numright ++;
            }
            l++;
            r--;
        }
        return (numleft == numright);
    }
};
