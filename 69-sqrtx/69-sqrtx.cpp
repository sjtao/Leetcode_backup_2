class Solution {
public:
    int mySqrt(int x) {
        if(x == 1) return 1;
        int l = 2;
        int r = x / 2;
        while(l <= r){
            int m = l + (r - l) / 2;
            if(m > x / m){
                r = m-1;
            }
            else if(m < x / m){
                l = m+1;
            }else{
                return m;
            }
        }
        return r;
    }
};