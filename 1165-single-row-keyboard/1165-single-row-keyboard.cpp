class Solution {
public:
    int calculateTime(string keyboard, string word) {
        unordered_map<char, int> mp;
        for(int i = 0; i < keyboard.length(); ++i){
            mp[keyboard[i]] = i; 
        }
        
        int dis = 0;
        int i = 0, j = 0;
        for(char s : word){
            j = mp[s];
            dis += abs(i - j);
            i = j;
        }
        
        return dis;
    }
};