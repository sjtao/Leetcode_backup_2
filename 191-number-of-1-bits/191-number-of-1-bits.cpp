class Solution {
public:
    int hammingWeight(uint32_t n) {
        int one = 0;
        while(n){
            one ++;
            n &= (n-1);
        }
        return one;
    }
};