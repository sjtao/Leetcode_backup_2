//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sum of Unique Elements.
//Memory Usage: 7.9 MB, less than 59.70% of C++ online submissions for Sum of Unique Elements.

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        //nums[i] <= 100
        vector<int> occur(101, 0);
        for(int i = 0; i < nums.size(); i++){
            occur[nums[i]] ++;
        }
        int sum = 0;
        for(int i = 0; i < 101; i++){
            if(occur[i] == 1){
                sum += i;
            }
        }
        return sum;
    }
};
