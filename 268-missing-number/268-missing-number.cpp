class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int s = n * (n + 1) / 2;
        for(int a : nums)
            s -= a;
        return s;
    }
};