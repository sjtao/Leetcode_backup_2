class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        if(n <= numRows || numRows == 1) return s;
        vector<string> r(numRows,"");
        int i = 0;
        int zig = -1;
        for(char c:s){
            r[i] += c;
            if(i == 0 || i == numRows-1) zig = -zig;
            i += zig;
        }
        
        string ans = "";
        for(int i = 0; i < numRows; i++){
            ans += r[i];
        }
        return ans;
    }
};