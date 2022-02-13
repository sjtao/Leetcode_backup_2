class Solution {
public:
    int devideconquer(vector<int>& nums, int l, int r){
        if(l > r)
            return INT_MIN;
        
        int m = l + (r - l)/2;
        int cur = 0;
        int bestleft = 0;
        int bestright = 0;
        for(int i = m-1; i >= l; i--){
            cur += nums[i];
            bestleft = max(cur, bestleft);
        }
        
        cur = 0;
        for(int i = m+1; i <= r; i++){
            cur += nums[i];
            bestright = max(cur, bestright);
        }
        
        int bestsum = nums[m] + bestright + bestleft;
        
        int lefthalf = devideconquer(nums, l, m-1);
        int righthalf = devideconquer(nums, m+1, r);
        
        return max(max(lefthalf, righthalf), bestsum);
    }
    
    int maxSubArray(vector<int>& nums) {
        //Divide and Conquer
        return devideconquer(nums, 0, nums.size()-1);
    }
};