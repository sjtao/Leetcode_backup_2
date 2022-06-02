class Solution {
public:
    unordered_map<string,int> mp;    
    int dfs(int a, int b){
        string s = to_string(a) + "," + to_string(b);
        if(mp.find(s) != mp.end()){
            return mp[s];
        }
        if(a + b == 0)
            return 0;
        else if(a + b == 2)
            return 2;
        else{
            int r = min(dfs(abs(a-2), abs(b-1)), dfs(abs(a-1), abs(b-2)))+1;
            mp[s] = r;
            return r;
        } 
    }
    
    int minKnightMoves(int x, int y) {
        // -300 <= x,y <= 300
        // 0 <= |x|+|y| <= 300
        return dfs(abs(x), abs(y));
    }
};