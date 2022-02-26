class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int n = s.length();
        int start = 0;
        for(auto a : shift){
            if(a[0] == 0){
                //left
                start -= a[1];
                start %= n;
                if(start < 0)
                    start += n;
            }
            if(a[0] == 1){
                //right
                start += a[1];
                start %= n;
            }
        }
        string ans = s;
        for(int i = 0; i < n; i++)
            ans[(start+i)%n] = s[i];
        
        return ans;
    }
};