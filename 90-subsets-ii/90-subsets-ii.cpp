class Solution {
public:
    vector<vector<int>> res;
    int n;
    
    void helper(vector<int>& nums, vector<int>& tem, int d){
        if(d == n)
            return;
        
        for(int i = d; i < n; i++){
            if((i != d && nums[i] == nums[d]) || (i != d && nums[i] == nums[i-1]))
                continue;
            tem.push_back(nums[i]);
            res.push_back(tem);
            helper(nums, tem, i+1);
            tem.pop_back();
        }
        
        return;
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n = nums.size();     
        sort(nums.begin(), nums.end()); 
        vector<int> tem;
        res.push_back(tem);
        helper(nums, tem, 0);
        return res;
    }
};