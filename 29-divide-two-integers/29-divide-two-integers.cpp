class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        int sign = (dividend > 0 ^ divisor > 0) ?  -1 : 1;
        long dd = abs(dividend), dv = abs(divisor), ans = 0;
        while(dv <= dd){
            long temp = dv, m = 1;
            while (temp << 1 <= dd) {
                temp <<= 1;
                m <<= 1;
            }
            dd -= temp;
            ans += m;
        }
        return sign * ans;
    }
};