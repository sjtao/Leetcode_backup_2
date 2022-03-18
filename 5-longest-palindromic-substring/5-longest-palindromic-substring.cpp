class Solution {
public:
    int n;
    int expand(string s, int l, int r){
        int L = l, R = r;
        while(L >= 0 && R < n && s[L] == s[R]){
            L--;
            R++;
        }
        return R-L-1;
    }
    string longestPalindrome(string s) {
        n = s.length();
        vector<vector<bool>> dp(n, vector(n, false));
        int st = 0, lenth = 0;
        for(int i = 0; i < n; i++){
            int len = max(expand(s, i, i), expand(s, i, i+1));
            if(len > lenth){
                st = i - (len-1)/2;
                lenth = len;
            }
        }

        return s.substr(st, lenth);
    }
};