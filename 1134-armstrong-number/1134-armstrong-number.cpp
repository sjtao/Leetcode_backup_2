class Solution {
public:
    bool isArmstrong(int n) {
        int m = n;
        int k = log10(n)+1;
        int arm = 0;
        while(m > 0){
            arm += pow(m%10, k);
            m /= 10;
        }
        return arm == n;
    }
};