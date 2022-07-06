class Solution {
public:
    int characterReplacement(string s, int k) {
        
        vector<int> mp(26,0);
        int res = 0, mx = 0;
        
        int n = s.length();
        if(n == k) return n;
        
        for(int i = 0; i < n; i++){
            mx = max(mx, mp[s[i]-'A']++);
            if(res - mx <= k)
                res++;
            else
                mp[s[i-res]-'A']--;
        }
        
        return res;
    }
};