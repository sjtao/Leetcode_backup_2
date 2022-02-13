class Solution {
public:
    int mySqrt(int x) {
        if(x < 2) return x;
        if(x < 4)  return 1;
        if(x == 4) return 2;
        // when x > 4; sqrt(x) < x/2
        int l = 2, r = x/2, m;
        long s;
        while(l <= r){
            m = l + (r - l) /2;
            s = (long)m * m;
            if(s > x) r = m-1;
            else if(s < x) l = m+1;
            else return m;
        }
        return r;
    }
};