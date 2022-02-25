class Solution {
public:
    int HALF_INT_MIN = -1073741824;
    
    int divide(int dividend, int divisor) {
        if(dividend == 0) return 0;
        if(dividend == INT_MIN && divisor == -1) return INT_MAX; //overflow
        if(dividend == INT_MIN && divisor == 1) return INT_MIN; //overflow

        int sign = 1;
        if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
            sign = -1;
        
        //convert to negative numbers
        dividend = dividend > 0  ? -dividend : dividend;
        divisor = divisor > 0 ? -divisor : divisor;
        
        int ans = 0;

        while(divisor >= dividend){
            int power = -1;
            int value = divisor;
            while(value >= HALF_INT_MIN && value + value >= dividend){
                power += power;
                value += value;
            }
            ans += power;
            dividend -= value;
        }
        
        if(sign == 1)
            ans = -ans;
        
        return ans;  
    }
};