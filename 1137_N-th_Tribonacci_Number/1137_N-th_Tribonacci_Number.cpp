/**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for N-th Tribonacci Number.
Memory Usage: 6.4 MB, less than 5.36% of C++ online submissions for N-th Tribonacci Number.
*/
class Solution {
private:
    unordered_map<int,int> m;
public:
    int triHelper(int n){
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        
        if(m.find(n) == m.end())
            m[n] = triHelper(n-1) + triHelper(n-2) + triHelper(n-3);
        
        return m[n];
    }
    int tribonacci(int n) {
        return triHelper(n);
    }
};
