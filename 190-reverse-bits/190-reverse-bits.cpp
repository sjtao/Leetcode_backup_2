class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t r = 0;
        int k = 0;
        while(k < 32){
            if(k != 0) r <<= 1;
            r += n & 1;
            n >>= 1;
            k++;
        }
        return r;
    }
};