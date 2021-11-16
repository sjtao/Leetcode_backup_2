//untime: 4 ms, faster than 90.70% of C++ online submissions for Find Greatest Common Divisor of Array.
//Memory Usage: 12.4 MB, less than 62.31% of C++ online submissions for Find Greatest Common Divisor of Array.

class Solution {
public:
    int GCDhelper(int a, int b){
        if (b == 0) return a;
        return gcd(b, a % b);
    
    }
    
    int findGCD(vector<int>& nums) {
        double mx = *max_element(nums.begin(), nums.end());
        double mi = *min_element(nums.begin(), nums.end());
        int ans = GCDhelper(mx, mi);
        return ans;
    }
};
