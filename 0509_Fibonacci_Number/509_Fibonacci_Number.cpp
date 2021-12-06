/**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Fibonacci Number.
Memory Usage: 6.3 MB, less than 10.82% of C++ online submissions for Fibonacci Number.
*/

class Solution {
private:
    unordered_map<int, int> fm;
public:
    int fibHelper(int n){
        if(n == 0 || n == 1) return n;   
        if(fm.find(n) == fm.end()){
            fm[n] = fibHelper(n-1)+fibHelper(n-2);
        }
        return fm[n];
    }
    
    int fib(int n) {
        return fibHelper(n);
    }
};
