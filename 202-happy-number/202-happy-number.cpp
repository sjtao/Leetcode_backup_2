class Solution {
public:
    unordered_set<int> st;
    int sqsum(int n){
        int sum = 0;
        int r;
        while(n > 0){
            r = n % 10;
            sum += r * r;
            n /= 10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        if(n == 1)
            return true;
        
        while(n > 1){
            n = sqsum(n);
            if(st.count(n))
                return false;
            else
                st.insert(n);
        }
        
        return true;
        
    }
};