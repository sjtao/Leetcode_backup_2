class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum = 0;
        int prod = 1;
        int m;
        while(n > 0){
            m = n % 10;
            sum += m;
            prod *= m;
            n /= 10;
        }
        return prod - sum;
    }
};