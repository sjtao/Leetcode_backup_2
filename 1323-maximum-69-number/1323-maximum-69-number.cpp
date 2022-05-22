class Solution {
public:
    int maximum69Number (int num) {
        int n = num;
        int six = -1, cnt = 0;
        while(n > 0){
            if(n % 10 == 6)
                six = cnt;
            n /= 10;
            cnt++;
        }
        
        return six == -1 ? num : num + pow(10, six) * 3;
    }
};