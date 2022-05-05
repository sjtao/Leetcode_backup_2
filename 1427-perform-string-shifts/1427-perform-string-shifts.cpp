class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int len = s.length();
        int start = 0;
        for(vector<int> p : shift){
            if(p[0] == 0)
                start += p[1];//left
            else if(p[0] == 1)
                start -= p[1];//right
        }
        
        start %= len;        
        start = (start + len) % len;
        string ans = "";
        for(int i = start; i < start + len; i++){
            ans += s[i % len];
        }
        return ans;
    }
};