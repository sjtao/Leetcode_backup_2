/**
Runtime: 1168 ms, faster than 18.85% of C++ online submissions for Implement strStr().
Memory Usage: 7.1 MB, less than 62.49% of C++ online submissions for Implement strStr().
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int h = haystack.length();
        int n = needle.length();
        
        if(h == 0 && n != 0) return -1;
        if(n == 0) return 0;
        
        int i = 0, j;
        while(i < h){
            if(haystack[i] == needle[0]){
                for(j = 1; j < n; j++){
                    if(haystack[i+j] != needle[j]){
                        break;
                    }
                }
                if(j == n){
                    return i;
                }
            }
            i++;
        }
        return -1;
    }
};

/**
Runtime: 512 ms, faster than 40.49% of C++ online submissions for Implement strStr().
Memory Usage: 7.1 MB, less than 90.09% of C++ online submissions for Implement strStr().
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int h = haystack.length();
        int n = needle.length();
        
        if(h < n) return -1;
        if(n == 0) return 0;
        
        int i = 0, j;
        while(i <= h-n){
            if(haystack[i] == needle[0]){
                for(j = 1; j < n; j++){
                    if(haystack[i+j] != needle[j]){
                        break;
                    }
                }
                if(j == n){
                    return i;
                }
            }
            i++;
        }
        return -1;
    }
};
