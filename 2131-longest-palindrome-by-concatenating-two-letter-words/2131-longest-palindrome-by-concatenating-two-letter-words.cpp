class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size();
        //provided constraint: words[i].length == 2
        
        unordered_map<string, int> mp;
        int len = 0;
        for(string t : words){
            string rev = t;
            rev[0] = t[1];
            rev[1] = t[0];
            if(mp.find(rev) == mp.end() || mp[rev] == 0){ //no strings in the map having reversed form
                mp[t]++;
            }
            else{
                mp[rev]--; //having strings in the map having reversed form
                len += 4;
            }
        }
        
        //count if there are strings having form "aa" left in the map
        int r = 0;
        for(auto it : mp){
            if(it.second > 0 && it.first[0] == it.first[1])
                r++;
        }
        
        if(r > 0) len += 2; //"aa" in the center
        
        return len;
        
    }
};