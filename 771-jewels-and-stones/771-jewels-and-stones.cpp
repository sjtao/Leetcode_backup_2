class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        
        set<char> jw;
        for(char j : jewels)
            jw.insert(j);
        
        int res = 0;
        for(char s : stones){
            res += jw.count(s);
        }
        
        return res;
    }
};