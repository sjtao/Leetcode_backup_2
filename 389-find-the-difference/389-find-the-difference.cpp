class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum = 0;
        for(char c : t)
            sum += (c-'a');
        for(char c : s)
            sum -= (c-'a');
        
        return sum + 'a';
    }
};