class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> st(26, 0);
        
        for(char c:s)
            st[c-'a']++;
        
        for(char c:t)
            st[c-'a']--;
        
        char a;
        for(int i = 0; i < 26; ++i){
            if(st[i] != 0){
                a = 'a' + i;
                break;
            }
        }
        
        return a;
        
    }
};