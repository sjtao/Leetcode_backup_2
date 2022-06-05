class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int n = word.length();
        int m = abbr.length();
        if(m > n) return false;
        
        int i = 0, j = 0;
        int abb = 0;
        while(i < n && j < m){
            if(isdigit(abbr[j])){
                while(isdigit(abbr[j])){
                    if(abb == 0 && abbr[j] == '0') return false;
                    abb = abb * 10 + (abbr[j++] - '0');
                }
                i += abb;
                abb = 0; 
            }
            else{
                if(word[i++] != abbr[j++])
                    return false;
            }
        }
        return i == n && j == m;
    }
};