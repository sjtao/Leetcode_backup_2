class Solution {
public:
    int squaresum(int a){
        int r, sum = 0;
        while(a){
            r = a % 10;
            sum += r * r;
            a /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {    
        int slow = n;
        int fast = squaresum(n);
        while(fast != 1 && slow != fast){
            slow = squaresum(slow);
            fast = squaresum(squaresum(fast));
        }
        return fast == 1;
    }
};