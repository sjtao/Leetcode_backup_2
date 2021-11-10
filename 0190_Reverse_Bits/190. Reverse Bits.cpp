//Runtime: 4 ms, faster than 47.66% of C++ online submissions for Reverse Bits.
//Memory Usage: 5.9 MB, less than 79.94% of C++ online submissions for Reverse Bits.
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for(int i = 0; i < 32; i++){
            ans += ((n << i)>>31) << i;
        }
        return ans;
    }
};
