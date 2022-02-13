class Solution {
public:
    unordered_map<int, int> mp;
    int dp_helper(int n){
        if(n <= 1)
            mp[n] = 1;
        
        for(int i = 2; i <= n; i++){
            if(mp.count(i) == 0){
                mp[i] = dp_helper(i-1) + dp_helper(i-2);
            }
        }
        
        return mp[n];
    }
    int climbStairs(int n) {
        return dp_helper(n);
    }
};