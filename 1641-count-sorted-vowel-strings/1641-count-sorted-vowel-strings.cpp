class Solution {

public:
    int Vowel(int n, int start){
        if(n == 0)
            return 1;
        
        int result = 0;
        for(int i = start; i <= 5; i++){
            result += Vowel(n-1, i);
        }
        return result;
    }
    int countVowelStrings(int n) {
        return Vowel(n, 1);
    }
};