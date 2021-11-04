//Runtime: 744 ms, faster than 6.89% of C++ online submissions for Two Sum.
//Memory Usage: 10.1 MB, less than 80.30% of C++ online submissions for Two Sum.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> index;
        bool find = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < nums.size(); j++){
                if((i != j) && (nums[i] + nums[j] == target)){
                    index.push_back(i);
                    index.push_back(j);
                    find = 1;
                    break;
                }    
            }
            if (find) break;
        }
        return index;
    }
};
