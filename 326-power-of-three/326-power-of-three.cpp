class Solution {
public:
    bool isPowerOfThree(int n) {
        //n = 3^x, log(n) = x log(3)
        if (n <= 0) return false;
        return fmod(log10(n)/log10(3), 1) == 0;
    }
};