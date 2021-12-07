/**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Pow(x, n).
Memory Usage: 5.9 MB, less than 42.03% of C++ online submissions for Pow(x, n).
*/

class Solution {

public:
    double PowHelper(double x, int n){
        if(n == 0) return 1;
        if(n == 1) return x;
        
        double pm = PowHelper(x, n/2);
        if(n%2 == 0)
           return pm * pm;
        else
           return pm * pm * x;
    }
    
    double myPow(double x, int n) {
        long L = n;
        if(n >= 0)
            return PowHelper(x, L);
        else
            return PowHelper(1/x, -L);  
    }
};
