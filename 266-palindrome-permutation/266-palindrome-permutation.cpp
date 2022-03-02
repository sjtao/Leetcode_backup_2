class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> letter(26,0);
        for(char c : s){
            if(letter[c-'a'] == 1)
                letter[c-'a'] -= 1;
            else if(letter[c-'a'] == 0)
                letter[c-'a'] += 1;
        }
        int sum = 0;
        for(int i = 0; i < 26; i++)
            sum += letter[i];
        
        return sum == 1 || sum == 0;
    }
};