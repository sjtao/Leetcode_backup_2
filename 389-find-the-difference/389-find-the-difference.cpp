class Solution {
public:
    char findTheDifference(string s, string t) {
        int ns = s.length();
        int ssum = 0;
        int tsum = t[ns];
        for(int i = 0; i < ns; ++i){
            ssum += s[i];
            tsum += t[i];
        }
        return (char)(tsum - ssum);
        
    }
};