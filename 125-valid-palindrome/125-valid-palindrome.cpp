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
            while(l < r && !((s[l] >= 48 && s[l] <= 57) || (s[l] >= 65 && s[l] <= 90) || (s[l] >= 97 && s[l] <= 122)))
                l++;
            while(l < r && !((s[r] >= 48 && s[r] <= 57) || (s[r] >= 65 && s[r] <= 90) || (s[r] >= 97 && s[r] <= 122)))
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