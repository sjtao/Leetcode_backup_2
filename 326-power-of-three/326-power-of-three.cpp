class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        if(n == 1) return true;
        if(n > 1 && n % 3 != 0) return false;
        double x = log10(n)/log10(3);
        int k = (int)x;
        return k == x;
    }
};