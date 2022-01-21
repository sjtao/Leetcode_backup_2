class Solution {
public:
    void push(vector<string>& ans, int a, int b){
        if(a == b)
            ans.push_back(to_string(a));
        else
            ans.push_back(to_string(a) + "->" + to_string(b));
        return;
    }
    
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<string> ans;
        if(n == 0){
            push(ans, lower, upper);
            return ans;
        }
        
        if(lower < nums[0])
            push(ans, lower, nums[0] - 1);
        
        for(int i = 1; i < n; ++i){
            if(nums[i] - nums[i-1] == 1)
                continue;
            
            push(ans, nums[i-1]+1, nums[i]-1);
        }
        
        if(nums[n-1] < upper)
            push(ans, nums[n-1]+1, upper);

        return ans;
    }
};