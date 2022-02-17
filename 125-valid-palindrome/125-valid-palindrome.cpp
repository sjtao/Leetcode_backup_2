class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length()-1;
        //number ascii 48-57
        //upper ascii 65-90
        //lower ascii 97-122
        while(l < r){
            //removing all non-alphanumeric characters
            while(l < r && !(isalnum(s[l])))
                l++;
            while(l < r && !(isalnum(s[r])))
                r--;
            //converting all uppercase letters into lowercase letters 
            if(s[l] - 'A' >= 0 && s[l] - 'A' < 26)
                s[l] += ('a' - 'A');
            if(s[r] - 'A' >= 0 && s[r] - 'A' < 26)
                s[r] += ('a' - 'A');
            if(s[l] == s[r]){
                l++; 
                r--;
            }
            else
                return false;
        }
        return true;
    }
};