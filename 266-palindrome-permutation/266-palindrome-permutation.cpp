class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> letter(26,0);
        for(char c : s)
            letter[c-'a'] ++;
        
        int sum = 0;
        for(int i = 0; i < 26; i++)
            sum += letter[i] % 2;
        
        return sum <= 1;
    }
};