
//Runtime: 12 ms, faster than 25.97% of C++ online submissions for Arranging Coins.
//Memory Usage: 5.8 MB, less than 70.45% of C++ online submissions for Arranging Coins.c

class Solution {
public:   
    int arrangeCoins(int n) {
        if(n == 1) return 1;
        int sum = n;
        int i = 0;
        while(sum >= 0){
            i++;
            sum -= i;          
        }
        return i-1;
    }
};



//Runtime: 4 ms, faster than 68.61% of C++ online submissions for Arranging Coins.
//Memory Usage: 5.9 MB, less than 70.45% of C++ online submissions for Arranging Coins.

class Solution {
public:
    int arrangeCoins(int n) {
        //k-row: k(k+1)/2 <= n
        //solve equation for k
        return (int)(sqrt(0.25+2*(long)n)-0.5);
    }
};
