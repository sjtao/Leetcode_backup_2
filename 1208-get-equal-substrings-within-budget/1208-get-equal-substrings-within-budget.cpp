class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        int i = 0, j = 0;
        int cost = 0;
        int len = 0;
        for(i = 0; i < n; i++){
            cost += abs(s[i] - t[i]);
            while(cost > maxCost){
                cost -= abs(s[j] - t[j]);
                j++;
            }
            len = max(i-j+1, len);
        }
        if(j == 0) len = n;
        
        return len;
    }
};