class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> cnt(101, 0);
        int n = nums.size();
        vector<int> res(101, 0);
        
        
        for(int i = 0; i < n; i++)
            cnt[nums[i]]++;
        
        for(int i = 1; i < 101; i++)
            res[i] = res[i-1] + cnt[i-1];
        
        for(int i = 0; i < n; i++)
            nums[i] = res[nums[i]];
        
        return nums;
    }
};