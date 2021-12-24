/**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of 1 Bits.
Memory Usage: 5.9 MB, less than 46.59% of C++ online submissions for Number of 1 Bits.
*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum = 0;
        while(n){
            sum++;
            n &= (n-1);
        }
        return sum;
    }
};
