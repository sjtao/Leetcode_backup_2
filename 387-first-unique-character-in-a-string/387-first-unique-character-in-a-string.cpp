class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;
        for(char c : s)
            mp[c]++;
        int ans = -1;
        for(int i = 0; i < s.length(); ++i){
            if(mp[s[i]]==1){
                ans = i;
                break;
            }  
        }
        return ans;
    }
};