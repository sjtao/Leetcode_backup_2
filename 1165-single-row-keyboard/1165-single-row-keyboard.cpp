class Solution {
public:
    int calculateTime(string keyboard, string word) {
        vector<int> mp(26, -1);
        for(int i = 0; i < keyboard.length(); ++i){
            mp[keyboard[i]-'a'] = i; 
        }
        
        int dis = 0;
        int i = 0, j = 0;
        for(char s : word){
            j = mp[s-'a'];
            dis += abs(i - j);
            i = j;
        }
        
        return dis;
    }
};