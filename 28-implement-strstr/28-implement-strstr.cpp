class Solution {
public:
    int strStr(string haystack, string needle) {
        int n1 = haystack.length();
        int n2 = needle.length();
        if(n1 < n2) return -1;
        if(n2 == 0) return 0;
    
        int ans = -1;
        for(int i = 0; i <= n1-n2; ++i){
            string t = haystack.substr(i, n2);
            if(t == needle){
                ans = i;
                break;
            }
        }
        return ans;
    }
};