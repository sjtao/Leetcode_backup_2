class Solution {
public:
    bool isPowerOfThree(int n) {
        //n = 3^x, log(n) = x log(3)
        if (n <= 0) return false;
        while(n%3 ==0){
            n /= 3;
        }
        return n==1;
    }
};