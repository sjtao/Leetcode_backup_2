class Solution {
public:
    int arrangeCoins(int n) {
        if(n <= 1) return n;
        int l = 1, r = n;
        long m, s;
        while(l <= r){
            m = l + (r-l) / 2;
            s = m * (m+1) / 2;
            if(s > n)
                r = m - 1;
            else if(s < n)
                l = m + 1;
            else
                return (int) m;
        }
        return r;
    }
};