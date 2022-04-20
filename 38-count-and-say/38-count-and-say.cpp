class Solution {
public:
    string helper(int n){
        if(n == 1) 
            return "1";
        
        string s = helper(n-1);
        string ans = "";
        int cnt = 1;
        for(int i = 1; i < s.length(); ++i){
            if(s[i] == s[i-1])
                cnt++;
            else{
                ans += to_string(cnt) + s[i-1];
                cnt = 1;
            }
        }
        ans += to_string(cnt) + s[s.length()-1];
        return ans;
    }
    
    string countAndSay(int n) {
        return helper(n);
    }
};