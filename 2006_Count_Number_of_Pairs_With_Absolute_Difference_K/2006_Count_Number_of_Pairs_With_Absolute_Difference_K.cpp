//Runtime: 24 ms, faster than 33.34% of C++ online submissions for Count Number of Pairs With Absolute Difference K.
//Memory Usage: 12.3 MB, less than 68.67% of C++ online submissions for Count Number of Pairs With Absolute Difference K.

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int pair = 0;
        for(int i = 0; i < nums.size()-1; i++){
            for(int j = i+1; j < nums.size(); j++){
                if(nums[i] - nums[j] == k || nums[i] - nums[j] == -k)
                    pair ++;
            }
        }
        return pair;
    }
};
