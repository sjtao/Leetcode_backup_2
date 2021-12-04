//O(2^n)
//Time Limit Exceeded 
//recursive
class Solution {
public:
    
    int StairHelper(int n){
        if (n <= 2) return n;
        
        return StairHelper(n-1) + StairHelper(n-2);
    }
    
    int climbStairs(int n) {
        return StairHelper(n);
    }
};

//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Climbing Stairs.
//Memory Usage: 6.5 MB, less than 13.41% of C++ online submissions for Climbing Stairs.
//adding memoization --> DP
class Solution {
private:
    unordered_map<int,int> s;
public:
    
    int StairHelper(int n){
        if (n <= 2) return n;
        if(s.find(n)==s.end())
            s[n] = StairHelper(n-1) + StairHelper(n-2);
        return s[n];
    }
    
    int climbStairs(int n) {
        return StairHelper(n);
    }
};
