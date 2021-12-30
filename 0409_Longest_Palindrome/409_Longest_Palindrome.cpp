/**
Runtime: 19 ms, faster than 9.82% of C++ online submissions for Longest Palindrome.
Memory Usage: 7.6 MB, less than 13.33% of C++ online submissions for Longest Palindrome.
*/
class Solution {
public:
    int longestPalindrome(string s) {
        //Palindrome: a word, phrase, or sequence that reads the same backward as forward
        //e.g., madam or nurses run
        unordered_map<char, int> mp;
        for(char a : s){
            if(mp.count(a) > 0)
                mp.erase(a);
            else
                mp[a] ++;
        }
        int m = mp.size(); //# of char appeared odd times in s;
        int r = s.size() - m; //# of char appreared even times in s;
        return m == 0 ? r : r+1;
    }
};
