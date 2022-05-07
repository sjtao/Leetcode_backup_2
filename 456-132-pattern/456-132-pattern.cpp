class Solution {
public:
    bool find132pattern(vector<int>& nums) {   
        int n = nums.size();
        if(n < 3) return false;
        
        vector<int> minarray(n);
        minarray[0] = nums[0];
        
        for(int i = 1; i < n; i++)
            minarray[i] = min(minarray[i-1], nums[i]);
        
        int k = n;
        for(int j = n-1; j > 0; j--){
            if(nums[j] <= minarray[j])
                continue;
            auto it = lower_bound(nums.begin()+k, nums.end(), minarray[j]+1);
            k = it - nums.begin();
            if(k < n && nums[k] < nums[j])
                return true;
            k--;
            nums[k] = nums[j];
        }
        
        return false; 
    }
};