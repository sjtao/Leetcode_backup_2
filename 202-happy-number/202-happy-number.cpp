class Solution {
public:
    int sumsq(int n){
        int s = 0;
        while(n > 0){
            int r = n % 10;
            s += r * r;
            n /= 10;
        }
        return s;
    }
    
    unordered_set<int> st;
    bool isHappy(int n) {
        if(n == 1)
            return true;
        st.insert(n);
        n = sumsq(n);
        if(st.count(n))
            return false;
        return isHappy(n);        
    }
};