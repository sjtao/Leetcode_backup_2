class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bit(n+1, 0);
        for(int i = 1; i <= n; ++i)
            bit[i] = bit[i >> 1] + (i & 1);
        
        return bit;
    }
};