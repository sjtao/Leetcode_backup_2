class Solution {
public:
    int hammingWeight(uint32_t n) {
        int bits = 0;
        uint32_t m = 1;
        for(int i = 0; i < 32; i++){
            if((n & m) != 0)
                bits++;
            m <<= 1;
        }
        return bits;
    }
};