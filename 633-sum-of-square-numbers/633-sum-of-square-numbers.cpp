class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long a = 0; a <= sqrt(c); a++){
            double b = sqrt(1.0 * (c - a*a));
            if(b == (int)(b))
                return true;
        }
        return false;
    }
};