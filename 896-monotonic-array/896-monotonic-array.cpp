class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return true;
        bool increase = true;
        bool decrease = true;
        for(int i = 0; i < n-1; ++i){
            if(nums[i+1] > nums[i]) decrease = false;
            if(nums[i+1] < nums[i]) increase = false;
            
        }
        return increase || decrease;
    }
};