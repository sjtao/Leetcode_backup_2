class Solution {
public:
    unordered_map<int, string> mp;
    string helper(int n){
        if(n == 1) 
            mp[n] = "1";
        
        if(mp.find(n) == mp.end()){
            string s = helper(n-1);
            string ans = "";
            int cnt = 1;
            for(int i = 1; i < s.length(); ++i){
                if(s[i] == s[i-1])
                    cnt++;
                else{
                    ans += to_string(cnt);
                    ans += s[i-1];
                    cnt = 1;
                }
            }
            ans += to_string(cnt);
            ans += s[s.length()-1];
            mp[n] = ans;
        }
        
        return mp[n];
    }
    string countAndSay(int n) {
        return helper(n);
    }
};