class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        //ransomNote in magazin
        unordered_map<char, int> mp;
        for(char c : magazine)
            mp[c]++;
        for(char c : ransomNote){
            if(mp.find(c) == mp.end() || mp[c] == 0)
                return false;
            else
                mp[c]--;
        }
        return true;
    }
};