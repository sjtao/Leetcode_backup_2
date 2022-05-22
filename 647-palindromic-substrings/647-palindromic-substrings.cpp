class Solution {
public:
    int n;
    int countSubstrings(string s) {
        int num = 0;
        n = s.length();
        for(int i = 0; i < n; i++){
            num += palim(s, i, i); //odd;
            num += palim(s, i, i+1); //even
        }
        return num;
    }
    
    int palim(string s, int l, int r){
        int a = 0;
        while(l >= 0 && r < n){
            if(s[l] != s[r])
                break;
            l--;
            r++;
            a++;
        }
        return a;
    }
};