class Solution {
public:
    int percentageLetter(string s, char letter) {
        int n = s.length();
        double num = 0.0;
        for(char c : s){
            if(c == letter)
                num += 1.0;
        }
        
        num /= n;
        num *= 100;
        return (int)floor(num);
    }
};