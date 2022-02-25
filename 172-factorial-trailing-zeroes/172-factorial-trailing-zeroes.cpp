class Solution {
public:
    int trailingZeroes(int n) {
        //5
        int ans = 0;
        while(n > 0){
            n /= 5;
            ans += n;
        }
        return ans;
    }
};