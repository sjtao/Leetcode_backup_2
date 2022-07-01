class Solution {
public:
    unordered_map<int,int> mp;
    int fibhelper(int n){
        if(mp.find(n) != mp.end())
            return mp[n];
        
        if(n <= 1) return n;
        mp[n] = fibhelper(n-1) + fibhelper(n-2);
        return mp[n];
    }
    
    int fib(int n) {
        return fibhelper(n);
    }
};