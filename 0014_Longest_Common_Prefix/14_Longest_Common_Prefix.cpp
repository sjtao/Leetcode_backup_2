/**
Runtime: 4 ms, faster than 71.61% of C++ online submissions for Longest Common Prefix.
Memory Usage: 9.1 MB, less than 92.80% of C++ online submissions for Longest Common Prefix.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n == 0) return "";
        
        string ans = "";
        int ls = strs[0].length();
        int i = 0, j;
        while(i < ls){
            for(j = 1; j<n; j++){
                if(strs[0][i] != strs[j][i] || i > strs[j].length()){
                    return ans;
                }
            }
            if(j == n)
                ans += strs[0][i];
            i++;
        }
        return ans;
    }
};
