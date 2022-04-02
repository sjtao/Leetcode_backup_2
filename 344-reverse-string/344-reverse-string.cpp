class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        if(n == 1) return;
        
        int l = 0, r = n-1;
        while(l < r){
            char c = s[l];
            s[l] = s[r];
            s[r] = c;
            l++;
            r--;
        }
        
        return;
    }
};