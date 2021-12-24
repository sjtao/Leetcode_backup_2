/**
Runtime: 4 ms, faster than 31.24% of C++ online submissions for Power of Two.
Memory Usage: 5.7 MB, less than 87.32% of C++ online submissions for Power of Two.
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n < 1) return false;
        return (n & (n-1)) == 0;
    }
};

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n < 1) return false;
        if(n == 1) return true;
        if(n > 1 && n % 2 == 1)
            return false;

        return isPowerOfTwo(n/2);
    }
};
