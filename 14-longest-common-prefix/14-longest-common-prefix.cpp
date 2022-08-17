class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int ln = 201;
        for(string s : strs)
            ln = ln < s.length() ? ln : s.length();
        
        string ans = "";
        for(int i = 0; i < ln; i++){
            char c = strs[0][i];
            for(int j = 1; j < n; j++){
                if(c != strs[j][i])
                    return ans;
            }
            ans += c;
        }
        
        return ans;
    }
};