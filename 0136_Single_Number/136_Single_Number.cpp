//Runtime: 16 ms, faster than 87.89% of C++ online submissions for Single Number.
//Memory Usage: 16.8 MB, less than 99.20% of C++ online submissions for Single Number.
//sorting
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        
        int i = 0;
        while (i < nums.size()-1){
            if(nums[i] == nums[i+1]){
                i += 2;
            }
            else{
                return nums[i];
            }
        }
        
        return nums[i];
    }
};
