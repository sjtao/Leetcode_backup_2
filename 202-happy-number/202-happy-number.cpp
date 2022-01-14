class Solution {
public:
    int digitsum(int n){
        int sum = 0;
        while(n){
            sum += pow(n%10, 2);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        if(n == 1) return true;
        unordered_set<int> s;
        s.insert(n);
        while(n!=1){
            n = digitsum(n);
            if(s.find(n) != s.end())
                return false;
            else
                s.insert(n);
        }
        return true;
    }
};