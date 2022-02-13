class Solution {
private:
    unordered_map<char, int> mp ={{'I', 1}, 
    {'V', 5}, 
    {'X', 10}, 
    {'L', 50}, 
    {'C', 100}, 
    {'D', 500}, 
    {'M', 1000}};

public:
    int romanToInt(string s) {
        int n = s.length();
        int ans = 0;
        int i = 0;
        while(i < n){
            int a = mp[s[i]];
            if(i+1 < n){
                if((s[i] == 'I' && (s[i+1] == 'V' || s[i+1] == 'X')) ||
                  (s[i] == 'X' && (s[i+1] == 'L' || s[i+1] == 'C')) ||
                  (s[i] == 'C' && (s[i+1] == 'D' || s[i+1] == 'M'))){
                    a = mp[s[i+1]] - a;
                    i++;
                }     
            }
            ans += a;
            i++;
        }
        return ans;
    }
};