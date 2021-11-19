//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Hamming Distance.
//Memory Usage: 6 MB, less than 24.75% of C++ online submissions for Hamming Distance.
class Solution {
public:
    int countSetBits(int n)
    {
        int count = 0;
        while (n) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
    
    int hammingDistance(int x, int y) {
        return countSetBits(x^y);
    }
};
