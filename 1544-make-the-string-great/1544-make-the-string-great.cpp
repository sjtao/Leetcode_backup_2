class Solution {
public:
    string makeGood(string s) {
        int i = 0;
        int n = s.length();
        while(i < n-1){
            int d = s[i] - s[i+1];
            if(d == -32 || d == 32){
                s.erase(i, 2);
                n -= 2;
                if(i > 0)
                    i--;
            }
            else
                i++;               
        }
        return s;
    }
};