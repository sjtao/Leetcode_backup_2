class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 0) return false;
        if(n == 1) return true;
        if(n % 10 != 4 && n % 10 != 6)
            return false;
        
        while(n % 4 == 0)
            n /= 4;
        
        return n == 1;
    }
};