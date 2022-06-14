class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == 0) return nums[0];
        if(n == 1 && k % 2 == 1) return -1;
        int m = -1;
        for(int i = 0; i < n && i < k-1; i++){
            m = max(m, nums[i]);
        }
        
        if(k < n)
            m = max(m, nums[k]);
        
        return m;
    }
};