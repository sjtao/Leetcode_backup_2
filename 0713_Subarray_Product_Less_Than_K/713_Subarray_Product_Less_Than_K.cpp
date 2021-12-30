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
