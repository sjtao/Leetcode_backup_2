class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1) return true;
        int l = 1;
        int r = num/2;
        long long m, p;
        while(l <= r){
            m = l + (r - l) / 2;
            p = m * m;
            if(p > num)
                r = m - 1;
            else if(p < num)
                l = m + 1;
            else
                return true;
        }
        return false;
    }
};