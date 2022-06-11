class Solution {
public:
    int mySqrt(int x) {
        if(x < 2) return x;
        
        int l = 2, r = x / 2;
        while(l <= r){
            int m = l + (r - l) / 2;
            long p = (long)m * m;
            if(p < x)
                l = m + 1;
            else if(p > x)
                r = m - 1;
            else
                return m;
        }
        return r;
    }
};