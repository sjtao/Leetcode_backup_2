class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        for(string s : words)
            mp[s]++;
        
        int len = 0;
        for(string s : words){
            if(s[0] != s[1]){//ab
                string r = s;
                reverse(r.begin(), r.end());
                if(mp.find(r) != mp.end() && mp[s] > 0 && mp[r] > 0){
                    len += 4;
                    mp[r]--;
                    mp[s]--;
                }
            }
            else{//gg 
                if(mp[s] >= 2){
                    len += 4;
                    mp[s] -= 2;
                }
            }
        }
        
        for(string s : words){
            if(s[0] == s[1] && mp[s] > 0){
                len += 2;
                mp[s]--;
                break;
            }
        }
        
        return len;
    }
};