class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        if(n == numRows || numRows == 1)
            return s;
        
        unordered_map<int, string> mp;
        for(int i = 0; i < numRows; i++)
            mp[i] = "";
        
        int k = 0;
        int dir = -1;
        int i = 0;
        while(k < n){
            mp[i] += s[k++];
            if(i == 0 || i == numRows-1)
                dir *= -1;
            i += dir;
        }
        
        string ans = "";
        for(int i = 0; i < numRows; i++)
            ans += mp[i];
        
        return ans;
    }
};