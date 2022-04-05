class Solution {

public:
    int strStr(string haystack, string needle) {
        int nh = haystack.length();
        int nn = needle.length();
        if(nh < nn) return -1;
        for(int i = 0; i <= nh-nn; i++){
            if(haystack[i] == needle[0]){
                int j = 1;
                for(; j < nn; j++){
                    if(haystack[i+j] != needle[j])
                        break;
                }
                if(j == nn)
                    return i;
            }
        }
        return -1;
    }
};