class Solution {
public:
    int mySqrt(int x) {
        if(x == 1) return 1;
        int l = 2;
        int r = x / 2;
        while(l <= r){
            long m = l + (r - l) / 2;
            long p = m * m;
            if(p > x){
                r = m-1;
            }
            else if(p < x){
                l = m+1;
            }else{
                return m;
            }
        }
        return r;
    }
};