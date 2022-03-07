class Solution {
public:
    int sqsum(int a){
        int s = 0;
        while(a){
            int b = a % 10;
            a /= 10;
            s += b * b;
        }
        return s;
    }
    
    bool isHappy(int n) {
        if (n == 1) return true;
        set<int> st;
        st.insert(n);
        while(n != 1){
            n = sqsum(n);
            if(st.count(n))
                return false;
            st.insert(n);
        }
        return true;
    }
};