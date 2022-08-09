class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int le = strs[0].length();
        
        for(int i = 1; i < n; i++){
            if(le > strs[i].length())
                le = strs[i].length();
        }
        
        string ans = "";
        for(int i = 0; i < le; i++){
            char c = strs[0][i];
            int j = 1;
            for(; j < n; j++){
                if(c != strs[j][i])
                    break;
            }
            
            if(j == n)
                ans += c;
            else
                break;
        }
        
        return ans;
        
    }
};