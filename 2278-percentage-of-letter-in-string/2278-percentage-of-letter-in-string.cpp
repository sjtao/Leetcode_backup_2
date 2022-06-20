class Solution {
public:
    int percentageLetter(string s, char letter) {
        int n = s.length();
        int num = 0;
        for(char c : s){
            num += (c == letter);
        }
        
        return 100 * num / n;
    }
};