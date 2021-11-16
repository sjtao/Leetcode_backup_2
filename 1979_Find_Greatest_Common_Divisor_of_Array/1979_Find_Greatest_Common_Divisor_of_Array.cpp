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


//Runtime: 8 ms, faster than 50.30% of C++ online submissions for Find Greatest Common Divisor of Array.
//Memory Usage: 12.6 MB, less than 14.36% of C++ online submissions for Find Greatest Common Divisor of Array.
class Solution {
public:
    
    int findGCD(vector<int>& nums) {
        //1 <= nums[i] <= 1000
        int smallest = 1001;
        int largest = -1;
        
        for (int n : nums) {
            if (n > largest) largest = n;
            if (n < smallest) smallest = n;
        }
        
        for (int i=smallest; i>=1; i--) {
            if ((smallest % i == 0) && (largest % i == 0))
                return i;
        }
        
        return 1;
    }
};
