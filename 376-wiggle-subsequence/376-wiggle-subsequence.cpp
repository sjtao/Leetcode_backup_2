class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        int positive = 1, negative = 1;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] - nums[i-1] > 0){
                positive = negative + 1;
            }
            else if(nums[i] - nums[i-1] < 0){
                negative = positive + 1;
            }
        }
        return max(positive, negative);
    }
};