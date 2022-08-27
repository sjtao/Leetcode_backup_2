class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int a = 0;
        for(int i = 1; i <= n; i++)
            a ^= (i ^ nums[i-1]);
        return a;
    }
};