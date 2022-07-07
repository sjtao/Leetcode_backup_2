class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = 201;
        for(string s : strs){
            if (n > s.length())
                n = s.length();
        }
        
        int s = strs.size();
        string ans = "";
        for(int i = 0; i < n; i++){
            char c = strs[0][i];
            int j = 1;
            for(; j < s; j++){
                if(c != strs[j][i])
                    break;
            }
            if(j == s) ans += c;
            else break;
        }
        
        return ans;
    }
};