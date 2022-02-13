class Solution {
public:
    int numWaterBottles(int x, int y) {
        //x: numBottles
        //y: numExchange 
        int n = 0;
        while((x - n * (y-1)) / y != 0)
            n++;
        return x + n;
    }
};