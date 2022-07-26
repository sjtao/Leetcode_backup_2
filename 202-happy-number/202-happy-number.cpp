class Solution {
public:
    int sqsum(int n){
        int sum = 0;
        while(n > 0){
            int a = n % 10;
            sum += a * a;
            n /= 10;
        }
        return sum;
    }
    
    set<int> st;
    bool isHappy(int n) {
        if(n == 1)
            return true;
        
        st.insert(n);
        while(n > 1){
            int b = sqsum(n);
            if(b == 1)
                return true;
            else if(st.count(b))
                return false;
            st.insert(b);
            n = b;
        }
        
        return true;
    }
};