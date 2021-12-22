/**
Runtime: 4 ms, faster than 90.72% of C++ online submissions for Letter Case Permutation.
Memory Usage: 10.1 MB, less than 69.57% of C++ online submissions for Letter Case Permutation.
*/

class Solution {
public:
    void helper(vector<string>& ans, string s, int i){
        if (i == s.size()) {
            ans.push_back(s);
            return;
        }
        // save initial value
        char c = s[i];
        // path1: toggle lower/upper case
        s[i] = islower(c) ? toupper(c) : tolower(c);
        helper(ans, s, i + 1);
        // path2: reset back(NOT go to this path if c is digit)
        if (isalpha(c)) {
            s[i] = c;
            helper(ans, s, i + 1);
        }
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        helper(ans, s, 0);
        return ans;
    }
};
