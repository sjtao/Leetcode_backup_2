class Solution {
public:
    int maximum69Number (int num) {
        int notnine = -1;
        int n = num;
        int d = 0;
        while(n){
            if(n % 10 != 9)
                notnine = d;
            n /= 10;
            d++;
        }
        
        return notnine == -1 ? num : num + pow(10, notnine) * 3;
    }
};