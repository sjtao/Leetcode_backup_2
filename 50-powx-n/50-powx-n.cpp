class Solution {
public:
    double helper(double x, int n){
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n == 2) return x*x;
        int k = n/2;
        if(n%2 == 0){
            return helper(helper(x, k),2);
        }
        else{
            return helper(helper(x, k),2) * x;
        }
    }
    double myPow(double x, int n) {
        if(n == 0) return 1.0;
        if(x == 0 || x == 1) return x;
        bool nneg = n < 0 ? 1 : 0;
        bool xneg = x < 0 ? 1 : 0;
        int m = abs(n);
        double y = abs(x);
        double ans = helper(y, m);
        
        if(xneg)
            ans = m%2==0 ? ans : -ans;
        if(nneg)
            ans = 1.0 / ans;
        
        return ans;
        
        
    }
};