/**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Perfect Square.
Memory Usage: 5.9 MB, less than 16.65% of C++ online submissions for Valid Perfect Square.
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num < 2) return true;
        long left = 2, right = num/2, mid, power;
        while(left <= right){
            mid = left + (right - left) / 2;
            power = mid * mid;
            if(power > num)
                right = mid-1;
            else if (power < num)
                left = mid+1;
            else
                return true;
        }
        return false;
    }
};
