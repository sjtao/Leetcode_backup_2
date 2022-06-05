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
                abb = abb * 10 + (abbr[j] - '0');
                if(abb == 0 || abb > n)
                    return false;
            }
            else{
                i += abb;
                abb = 0;
                if(word[i++] != abbr[j])
                    return false;
            }
            j++;
        }
        return i + abb == n && j == m;
    }
};