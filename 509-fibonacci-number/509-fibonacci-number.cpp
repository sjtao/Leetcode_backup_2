class Solution {
public:
    unordered_map<int,int> mp;
    int dp(int n){
        if(n <= 1)
            return n;
        
        if(mp.find(n) == mp.end()){
            mp[n] = dp(n-1) + dp(n-2);
        }
        
        return mp[n];
    }
    int fib(int n) {
        return dp(n);
    }
};