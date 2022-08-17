class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for(char c : s){
            mp[c] ++;
        }
        
        int odd = 0;
        int even = 0;
        for(auto it : mp){
            if(it.second % 2 == 0)
                even += it.second;
            else{
                even += (it.second -1);
                odd++;
            }
        }
        
        return even + (odd >= 1);
    }
};