class Solution {
public:
    unordered_map<int, int> mp;
    int helper(int n){
        if(n <= 2) return n;
        if(mp.find(n) == mp.end())
            mp[n] = helper(n-1) + helper(n-2);
        return mp[n];
    }
    int climbStairs(int n) {
        return helper(n);
    }
};