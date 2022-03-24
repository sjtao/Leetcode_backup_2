class Solution {
public:
    bool arithmetic(vector<int> nums){
        //rearrange
        sort(nums.begin(), nums.end());
        int d = nums[1] - nums[0];
        for(int i = 1; i < nums.size()-1; i++){
            if(nums[i+1] - nums[i] != d)
                return false;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = l.size();
        vector<bool> ans(n);
        for(int i = 0; i < n; i++){
            if(r[i] - l[i] < 2)
                ans[i] = true;
            else{
                ans[i] = arithmetic({nums.begin()+l[i],nums.begin()+r[i]+1});
            }
            
        }
        return ans;
    }
};