class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> cnt(101, 0);
        int n = nums.size();
        
        for(int i = 0; i < n; i++)
            cnt[nums[i]]++;
        
        for(int i = 1; i < 101; i++)
            cnt[i] += cnt[i-1];
        
        for(int i = 0; i < n; i++){
            if(nums[i] != 0)
                nums[i] = cnt[nums[i]-1];
        }
        
        return nums;
    }
};