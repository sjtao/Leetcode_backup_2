//Runtime: 64 ms, faster than 54.47% of C++ online submissions for Valid Palindrome II.
//Memory Usage: 23.4 MB, less than 50.43% of C++ online submissions for Valid Palindrome II.

class Solution {
public:
    bool PalindromeHelper(string s){
        int i = 0;
        int j = s.length() - 1;
         while(i < j){
            if (s[i] == s[j]){
                i++;
                j--;
            }
            else{
                return 0;
            }
        }
        return 1;
    }
    
    bool validPalindrome(string s) {
        if(s.length() <= 2) return 1;
        
        int i = 0;
        int j = s.length() - 1;

        while(i < j){
            if (s[i] == s[j]){
                i++;
                j--;
            }
            else{
                if(PalindromeHelper(s.substr(i+1, j-i)) || PalindromeHelper(s.substr(i, j-i))){
                    return 1;
                }
                else{
                    return 0;
                }
            }
        }
        
        return 1;
    }
};
