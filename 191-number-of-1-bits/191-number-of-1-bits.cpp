class Solution {
public:
    int hammingWeight(uint32_t n) {
        int one = 0;
        while(n > 0){
            one += (n & 1);
            n >>= 1;
        }
        return one;
    }
};