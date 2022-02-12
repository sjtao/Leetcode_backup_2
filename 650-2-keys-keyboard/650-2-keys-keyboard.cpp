class Solution {
public:
    int minSteps(int n) {
        //sum_i [copy*1+paste*x_i] = n
        int ans = 0; 
        int p = 2;
        while(n > 1){
            while(n % p == 0){
                n /= p;
                ans += p;
            }
            p++;
        }
        return ans;
    }
};