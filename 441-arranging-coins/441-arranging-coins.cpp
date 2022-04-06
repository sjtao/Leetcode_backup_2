class Solution {
public:
    int arrangeCoins(int n) {
        if(n == 1) return 1;
        int coin = n;
        int i = 1;
        for(; i < n; i++){
            coin -= i;
            if(coin <= 0)
                break;
        }
        return coin == 0 ? i : i-1;
    }
};