class Solution {
public:
    int sqsum(int n){
        int s = 0;
        while(n){
            int a = n % 10;
            s += a * a;
            n /= 10;
        }
        return s;
    }
    bool isHappy(int n) {
        if(n == 1) return true;
        set<int> st;
        st.insert(n);
        while(n > 1){
            n = sqsum(n);
            if(st.count(n))
                return false;
            st.insert(n);            
        }
        return true;
    }
};