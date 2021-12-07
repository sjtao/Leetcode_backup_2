/**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for K-th Symbol in Grammar.
Memory Usage: 6 MB, less than 40.24% of C++ online submissions for K-th Symbol in Grammar.
*/

class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n== 1 && k == 1) return 0;
        long half = pow(2, n-2);
        if(k <= half)
            return kthGrammar(n-1, k);
        else
            return !kthGrammar(n-1, k-half);
    }
};
