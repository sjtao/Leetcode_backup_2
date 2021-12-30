//TLE
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int n = nums.size();
        int s = 0;
        int count = 0;
        int i = s;
        int prod = 1;
        while(s < n){
            prod *= nums[i];
            if(prod < k) {count++; i++;}
            if(prod >= k || i == n) {s++; i = s; prod = 1;}
        }
        
        return count;
    }
};

/**
Runtime: 72 ms, faster than 78.14% of C++ online submissions for Subarray Product Less Than K.
Memory Usage: 61.3 MB, less than 20.97% of C++ online submissions for Subarray Product Less Than K.
*/
//sliding windows
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int n = nums.size();
        int count = 0;
        int prod = 1;
        int s = 0;
        for(int i = 0; i < n; i++){
            prod *= nums[i];
            while(prod >= k)
                prod /= nums[s++];
            count += (i - s + 1);
        }
        
        return count;
    }
};
