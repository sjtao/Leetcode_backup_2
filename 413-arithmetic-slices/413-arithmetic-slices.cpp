class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int dp = 0, sum = 0;
        for(int i = 1; i < nums.size()-1; i++){
            if(nums[i] - nums[i-1] == nums[i+1] - nums[i])
                dp = 1 + dp;
            else
                dp = 0;
            sum += dp;
        }
        return sum;
    }
};