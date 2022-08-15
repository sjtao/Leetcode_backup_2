class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int n = nums.size();
        int d = nums[n-1] - nums[0] - n + 1;
        if(d < k) return nums[n-1] + k - d;
        
        int l = 0, r = n-1;
        while(l < r){
            int m = l + (r - l) / 2;
            int d = nums[m] - nums[0] - m;
            if(d >= k) r = m;
            else l = m+1;
        }
        return  k + nums[0] + (l-1);
    }
};