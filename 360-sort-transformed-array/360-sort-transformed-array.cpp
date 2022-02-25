class Solution {
public:

    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            nums[i] = a * nums[i] * nums[i] + b * nums[i] + c;
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};