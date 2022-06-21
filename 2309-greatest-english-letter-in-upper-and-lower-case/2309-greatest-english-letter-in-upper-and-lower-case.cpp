class Solution {
public:
    string greatestLetter(string s) {
        vector<int> up(26, 0), lw(26, 0);
        
        string ans = "";
        for(char c : s){
            if(c - 'a' >= 0)
                lw[c-'a'] = 1;
            else if(c - 'A' >= 0)
                up[c-'A'] = 1;
        }
        
        for(int i = 25; i >= 0; i--){
            if(lw[i] == 1 && up[i] == 1){
                char c = 'A' + i;
                ans += c;
                return ans;
            }
        }
        
        return ans;
    }
};