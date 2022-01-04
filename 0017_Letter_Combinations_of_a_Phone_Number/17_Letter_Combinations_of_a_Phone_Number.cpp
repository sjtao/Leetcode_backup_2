/**
Runtime: 3 ms, faster than 16.04% of C++ online submissions for Letter Combinations of a Phone Number.
Memory Usage: 6.5 MB, less than 86.45% of C++ online submissions for Letter Combinations of a Phone Number.
*/

class Solution {
private:
    vector<string> v={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    int n;
    void combine(string digits, int d, string s, vector<string>& ans){
        if(d == n){
            ans.push_back(s);
            return;
        }
        
        for(int i = 0; i < v[digits[d]-'0'].size(); i++){
            combine(digits, d+1, s+v[digits[d]-'0'][i], ans);
        }
        return;
    }
    
    vector<string> letterCombinations(string digits) {
        n = digits.length();
        vector<string> ans;
        if(n == 0) return ans;
        string s = "";
        combine(digits, 0, s, ans);
        return ans;
    }
};
