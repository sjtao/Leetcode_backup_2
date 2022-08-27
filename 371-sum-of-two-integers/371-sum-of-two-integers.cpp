class Solution {
public:
    int getSum(int a, int b) {
        if(a == 0) return b;
        if(b == 0) return a;
        
        int ans;
        unsigned carry;
        while(b != 0){
            ans = a ^ b;
            carry = a & b;
            a = ans;
            b = carry << 1;
        }
        return ans;
    }
};