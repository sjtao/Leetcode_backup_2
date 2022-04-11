class Solution {
public:
    bool binarysearch(long s, long e, int n){
        if(e < s)
            return false;
        
        long m = s + (e-s)/2;
        if(m*m == n)
            return true;
        if(m*m > n)
            return binarysearch(s, m-1, n);
        return binarysearch(m+1, e, n);
    }
    
    bool judgeSquareSum(int c) {
        for(long a = 0; a*a <= c; a++){
            int b = c - a*a;
            if(binarysearch(0,b,b))
                return true;
        }
        return false;
    }
};