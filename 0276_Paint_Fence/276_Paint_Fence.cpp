/**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Paint Fence.
Memory Usage: 6.3 MB, less than 13.16% of C++ online submissions for Paint Fence.
*/

class Solution {
private:
    unordered_map<int, int> mp;
    int K;
public:
    int wayshelper(int n){
        if(n == 1) return K;
        if(n == 2) return K*K;
        if(mp.find(n) == mp.end()){
            mp[n] = (K-1)*(wayshelper(n-1) + wayshelper(n-2));
        }
        return mp[n];        
    }
    int numWays(int n, int k) {
        K = k;
        return wayshelper(n);
    }
};
