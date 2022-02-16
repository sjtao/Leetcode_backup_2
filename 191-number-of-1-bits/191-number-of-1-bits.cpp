class Solution {
public:
    int hammingWeight(uint32_t n) {
        int b = 0;
        while(n > 0){
            b += (n & 1);
            n >>= 1;
        }
        return b;
    }
};