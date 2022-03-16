class Solution {
public:
    int strStr(string haystack, string needle) {
        int n1 = haystack.length();
        int n2 = needle.length();
        if(n1 < n2) return -1;
        if(n2 == 0) return 0;

        for(int i = 0; i <= n1-n2; ++i){
            int j = 0;
            for(; j < n2; ++j){
                if(needle[j] != haystack[i+j]){
                    break;
                }
            }
            if(j == n2)
                return i;
        }
        return -1;
    }
};