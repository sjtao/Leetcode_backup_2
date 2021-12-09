/**
Runtime: 4 ms, faster than 53.40% of C++ online submissions for Sqrt(x).
Memory Usage: 5.9 MB, less than 73.64% of C++ online submissions for Sqrt(x).
*/

class Solution {
public:
    int mySqrt(int x) {
        if(x < 2) return x;
        
        int pivot, low = 2, high = x/2;
        long p2;
        while(low <= high){
            pivot = low + (high - low) / 2;
            p2 = (long)pivot * pivot;
            if(p2 == x) return pivot;
            if(p2 > x) high = pivot - 1;
            else       low  = pivot + 1;
        }
        return high;
    }
};
