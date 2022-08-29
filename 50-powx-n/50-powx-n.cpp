class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0) return 0;
        if(x == 1) return 1;
        if(n == 0) return 1;
        if(n == 1) return x;
        long long N = n;
        if(n < 0){
            x = 1/x;
            N = -N;
        }
        
        double res = 1.;
        double cur = x;
        for(long long i = N; i > 0; i /= 2){
            if(i % 2)
                res *= cur;
            cur *= cur;
        }
        
        return res;
        
    }
};