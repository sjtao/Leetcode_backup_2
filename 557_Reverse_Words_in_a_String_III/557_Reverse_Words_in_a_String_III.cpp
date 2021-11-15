//Runtime: 92 ms, faster than 5.60% of C++ online submissions for Reverse Words in a String III.
//Memory Usage: 364.9 MB, less than 5.11% of C++ online submissions for Reverse Words in a String III.

class Solution {
public:
    string reverseWords(string s) {
        string r, temp;
        for(int i = 0; i < s.length(); i++){
            if(s[i] != ' '){
                temp += s[i];
            }
            else{
                reverse(temp.begin(), temp.end());
                r = r + temp;
                r = r + s[i];
                temp.clear();
            }
        }
        reverse(temp.begin(), temp.end());
        r = r + temp;
        return r;
    }
};
