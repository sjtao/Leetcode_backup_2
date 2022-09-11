class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return min(nums[0], nums[1]);
        if(nums[n-1] > nums[0]) return nums[0]; //ordered
        
        int l = 0, r = n-1;
        while(l <= r){
            int m = l + (r-l)/2;
            if(nums[m] > nums[m+1])
                return nums[m+1];
            if(nums[m] < nums[m-1])
                return nums[m];
            if(nums[m] > nums[0])
                l = m+1;
            else
                r = m-1;
        }
        return -1;
    }
};