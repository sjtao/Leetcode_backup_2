class Solution {
public:
    unordered_map<int, int> mp;
    int dp_helper(int n){
        if(n <= 1)
            mp[n] = 1;
           
        if(mp.count(n) == 0){
            mp[n] = dp_helper(n-1) + dp_helper(n-2);
        }

        return mp[n];
    }
    int climbStairs(int n) {
        return dp_helper(n);
    }
};