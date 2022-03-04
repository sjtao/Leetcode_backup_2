class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        if(n == 1) return true;
        if(n > 1 && n % 3 != 0) return false;
        int x = round(log(n)/log(3));
        return n == pow(3, x);
    }
};