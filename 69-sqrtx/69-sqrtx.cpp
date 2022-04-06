class Solution {
public:
    int mySqrt(int x) {
        if(x < 2) return x;
        int l = 1, r = x, m;
        while(l <= r){
            m = l + (r-l) / 2;
            if(x / m > m)
                l = m + 1;
            else if(x / m < m)
                r = m - 1;
            else
                return m;
        }
        return r;
    }
};