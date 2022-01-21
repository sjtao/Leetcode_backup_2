class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<string> ans;
        if(n == 0){
            if(upper == lower)
                ans.push_back(to_string(lower));
            else
                ans.push_back(to_string(lower) + "->" + to_string(upper));
            return ans;
        }
        
        if(lower < nums[0]){
            if(lower == nums[0] - 1)
                ans.push_back(to_string(lower));
            else
                ans.push_back(to_string(lower) + "->" + to_string(nums[0] - 1));
        }
        
        for(int i = 1; i < n; ++i){
            if(nums[i] - nums[i-1] == 1)
                continue;
            int a = nums[i-1]+1;
            int b = nums[i]-1;
            if(a == b)
                ans.push_back(to_string(a));
            else
                ans.push_back(to_string(a) + "->" + to_string(b));
        }
        
        if(nums[n-1] < upper){
            if(upper == nums[n-1]+1)
                ans.push_back(to_string(upper));
            else
                ans.push_back(to_string(nums[n-1]+1) + "->" + to_string(upper));
        }
        
        return ans;
    }
};