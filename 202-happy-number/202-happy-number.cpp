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
        unordered_set<int> set;
        set.insert(n);
        while(n != 1){
            n = squaresum(n);
            if(set.count(n) == 0)
                set.insert(n);
            else
                return false;
        }
        return true;
    }
};