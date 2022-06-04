class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char, int> mp; //save the latest index of a char
        int start = 0;
        int lng = 0;
        for(int i = 0; i < n; i++){
            if(mp.find(s[i]) != mp.end()){
                start = max(start, mp[s[i]]+1); 
            }
            mp[s[i]] = i;
            lng = max(lng, i - start + 1);
        }
        return lng;
    }
};