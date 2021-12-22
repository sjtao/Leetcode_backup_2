/**
Runtime: 4 ms, faster than 40.68% of C++ online submissions for Happy Number.
Memory Usage: 6.4 MB, less than 5.87% of C++ online submissions for Happy Number.
*/

class Solution {
public:
    int squaresum(int n){
        int sum = 0, r;
        while(n){
            r = n % 10;
            sum += r * r;
            n = n / 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        if (n==1) return true;
        unordered_set<int> st;
        st.insert(0);
        while(st.count(n)==0){
            st.insert(n);
            n = squaresum(n);
            if(n == 1)
                return true;
        }
        
        return false;
        
    }
};

/**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Happy Number.
Memory Usage: 6.5 MB, less than 5.87% of C++ online submissions for Happy Number.
*/
class Solution {
public:
    int squaresum(int n){
        int sum = 0, r;
        while(n){
            r = n % 10;
            sum += r * r;
            n = n / 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        if (n==1) return true;
        unordered_set<int> st;
        st.insert(0);
        while(st.count(n)==0){
            st.insert(n);
            n = squaresum(n);
        }
        
        return (n==1);
        
    }
};
