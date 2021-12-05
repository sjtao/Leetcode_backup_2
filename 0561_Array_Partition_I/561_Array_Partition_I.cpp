/**
Runtime: 56 ms, faster than 40.69% of C++ online submissions for Array Partition I.
Memory Usage: 28.1 MB, less than 87.16% of C++ online submissions for Array Partition I.
*/

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int n = nums.size();
        if(n == 2) return min(nums[0], nums[1]);
        
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(int i = 0; i < n; i+=2){
            sum += nums[i];
        }
        return sum;
    }
};
